/*
 * See the dyninst/COPYRIGHT file for copyright information.
 * 
 * We provide the Paradyn Tools (below described as "Paradyn")
 * on an AS IS basis, and do not warrant its validity or performance.
 * We reserve the right to update, modify, or discontinue this
 * software at any time.  We shall have no obligation to supply such
 * updates or modifications or any other form of support to you.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "PCProcess.h"
#include "ProcessSet.h"

#include <list>
#include <vector>
#include <string>

#if !defined(PROCESSPLAT_H_)
#define PROCESSPLAT_H_

class int_process;
class sysv_process;
class thread_db_process;
class linux_process;
namespace bgq {
   class bgq_process;
};

#if !defined(_MSC_VER)
//For sigset_t
#include <signal.h>
#endif

namespace Dyninst {
namespace ProcControlAPI {

class PC_EXPORT LibraryTracking
{
   friend class ::sysv_process;
  protected:
   LibraryTracking(Process::ptr proc_);
   ~LibraryTracking();
   Process::weak_ptr proc;
   static bool default_track_libs;
  public:
   static void setDefaultTrackLibraries(bool b);
   static bool getDefaultTrackLibraries();

   bool setTrackLibraries(bool b) const;
   bool getTrackLibraries() const;
   bool refreshLibraries();
};

class PC_EXPORT LibraryTrackingSet
{
   friend class ProcessSet;
   friend class PSetFeatures;
  protected:
   LibraryTrackingSet(ProcessSet::ptr ps_);
   ~LibraryTrackingSet();
   ProcessSet::weak_ptr wps;
  public:
   bool setTrackLibraries(bool b) const;
   bool refreshLibraries() const;
};

class PC_EXPORT LWPTracking
{
   friend class ::linux_process;
   friend class bgq::bgq_process;
  protected:
   LWPTracking(Process::ptr proc_);
   ~LWPTracking();
   Process::weak_ptr proc;
   static bool default_track_lwps;
  public:
   static void setDefaultTrackLWPs(bool b);
   static bool getDefaultTrackLWPs();

   void setTrackLWPs(bool b) const;
   bool getTrackLWPs() const;
   bool refreshLWPs();
};

class PC_EXPORT LWPTrackingSet
{
   friend class ProcessSet;
   friend class PSetFeatures;
  protected:
   LWPTrackingSet(ProcessSet::ptr ps_);
   ~LWPTrackingSet();
   ProcessSet::weak_ptr wps;
  public:
   bool setTrackLWPs(bool b) const;
   bool refreshLWPs() const;
};

class PC_EXPORT ThreadTracking
{
   friend class ::thread_db_process;
  protected:
   ThreadTracking(Process::ptr proc_);
   ~ThreadTracking();
   Process::weak_ptr proc;
   static bool default_track_threads;
  public:
   static void setDefaultTrackThreads(bool b);
   static bool getDefaultTrackThreads();

   bool setTrackThreads(bool b) const;
   bool getTrackThreads() const;
   bool refreshThreads();
};

class PC_EXPORT ThreadTrackingSet
{
   friend class ProcessSet;
   friend class PSetFeatures;
  protected:
   ThreadTrackingSet(ProcessSet::ptr ps_);
   ~ThreadTrackingSet();
   ProcessSet::weak_ptr wps;
  public:
   bool setTrackThreads(bool b) const;
   bool refreshThreads() const;
};

class PC_EXPORT FollowFork
{
   friend class ::linux_process;
  protected:
   FollowFork(Process::ptr proc_);
   ~FollowFork();
   Process::weak_ptr proc;
  public:

   typedef enum {
      None,                      //Fork tracking not available on this platform.
      ImmediateDetach,           //Do not even attach to forked children.
      DisableBreakpointsDetach,  //Remove inherited breakpoints from children, then detach.
      Follow                     //Default. Attach and full control of forked children.
   } follow_t;

   static void setDefaultFollowFork(follow_t f);
   static follow_t getDefaultFollowFork();

   bool setFollowFork(follow_t b) const;
   follow_t getFollowFork() const;
  protected:
   static follow_t default_should_follow_fork;
};

class PC_EXPORT FollowForkSet
{
   friend class ProcessSet;
   friend class PSetFeatures;
  protected:
   FollowForkSet(ProcessSet::ptr ps_);
   ~FollowForkSet();
   ProcessSet::weak_ptr wps;
  public:
   bool setFollowFork(FollowFork::follow_t f) const;
};

class PC_EXPORT CallStackCallback
{
  private:
   static const bool top_first_default_value = false;
  public:
   bool top_first;
   CallStackCallback();
   virtual bool beginStackWalk(Thread::ptr thr) = 0;
   virtual bool addStackFrame(Thread::ptr thr, Dyninst::Address ra, Dyninst::Address sp, Dyninst::Address fp) = 0;
   virtual void endStackWalk(Thread::ptr thr) = 0;
   virtual ~CallStackCallback();
};

class PC_EXPORT CallStackUnwinding
{
  private:
   Thread::weak_ptr wt;
  public:
   CallStackUnwinding(Thread::ptr t);
   virtual ~CallStackUnwinding();
   bool walkStack(CallStackCallback *stk_cb) const;
};

class PC_EXPORT CallStackUnwindingSet
{
  private:
   ThreadSet::weak_ptr wts;
  public:
   CallStackUnwindingSet(ThreadSet::ptr ts);
   ~CallStackUnwindingSet();
   bool walkStack(CallStackCallback *stk_cb);
};

class PC_EXPORT MultiToolControl
{
   friend class bgq::bgq_process;
  public:
   typedef unsigned int priority_t;
  private:
   Process::weak_ptr proc;
  protected:
   MultiToolControl(Process::ptr p);
   ~MultiToolControl();
   static std::string default_tool_name;
   static priority_t default_tool_priority;
  public:
   static void setDefaultToolName(std::string name);
   static void setDefaultToolPriority(priority_t p);
   static std::string getDefaultToolName();
   static priority_t getDefaultToolPriority();
   
   //Tool name and priority cannot be changed after process creation.
   //To set these values, use the static methods to set the default,
   // values, then trigger your attach/create operation.
   std::string getToolName() const;
   priority_t getToolPriority() const;
};

#if defined(_MSC_VER)
typedef void* dyn_sigset_t;
#else
typedef sigset_t dyn_sigset_t;
#endif

//On posix system, the sigset referenced below is a pointer to a sigset_t
class PC_EXPORT SignalMask
{
   friend class ::int_process;
  protected:
   dyn_sigset_t the_sigset;
   static dyn_sigset_t default_sigset;
   static bool sigset_initialized;
   SignalMask();
   ~SignalMask();
  public:
   static dyn_sigset_t getDefaultSigMask();
   static void setDefaultSigMask(dyn_sigset_t s);
   dyn_sigset_t getSigMask() const;
   void setSigMask(dyn_sigset_t s);
};

class PC_EXPORT BGQData
{
   friend class ::int_process;
   friend class bgq::bgq_process;
  protected:
   static const unsigned int startup_timeout_sec_default = 45;
   static const bool block_for_ca_default = true;
   static unsigned int startup_timeout_sec;
   static bool block_for_ca;
   Process::weak_ptr proc;
  public:
   static void setStartupTimeout(unsigned int seconds);
   static void setBlockForControlAuthority(bool block);
   
   //Five coordinates on torus (a, b, c, d, e), one on CN (t)
   bool getProcCoordinates(unsigned &a, unsigned &b, unsigned &c, unsigned &d, unsigned &e, unsigned &t) const;

   //All processes that share a CN will shared a compute node ID
   unsigned int getComputeNodeID() const;

   bool getSharedMemRange(Dyninst::Address &start, Dyninst::Address &end) const;
   bool getPersistantMemRange(Dyninst::Address &start, Dyninst::Address &end) const;
   bool getHeapMemRange(Dyninst::Address &start, Dyninst::Address &end) const;
};

#if 0
//TO BE IMPLEMENTED

/**
 * This struct is copied from the GLIBC sources for 'struct stat64'.  It is 
 * recreated here because this header is supposed to compile without defines 
 * across several platforms that may not have stat64
 **/
struct stat64_ret_t {
	unsigned long long st_dev;		/* Device.  */
	unsigned long long st_ino;		/* File serial number.  */
	unsigned int	st_mode;	/* File mode.  */
	unsigned int	st_nlink;	/* Link count.  */
	unsigned int	st_uid;		/* User ID of the file's owner.  */
	unsigned int	st_gid;		/* Group ID of the file's group. */
	unsigned long long st_rdev;	/* Device number, if device.  */
	unsigned short	__pad2;
	long long	st_size;	/* Size of file, in bytes.  */
	int		st_blksize;	/* Optimal block size for I/O.  */
	long long	st_blocks;	/* Number 512-byte blocks allocated. */
	int		st_atime;	/* Time of last access.  */
	unsigned int	st_atime_nsec;
	int		st_mtime;	/* Time of last modification.  */
	unsigned int	st_mtime_nsec;
	int		st_ctime;	/* Time of last status change.  */
	unsigned int	st_ctime_nsec;
	unsigned int	__unused4;
	unsigned int	__unused5;
};

struct FileInfo {
   FileInfo(std::string f) : filename(f), stat_results(NULL) {}
   FileInfo() : stat_results(NULL) {}
   ~FileInfo() { if (stat_results) free(stat_results); stat_results = NULL; }

   std::string filename;
   stat64_ret_t *stat_results; //Filled in by getFileStatData
};
typedef std::multimap<Process::const_ptr, FileInfo> FileSet;

class PC_EXPORT RemoteIO : virtual public PlatformFeatures
{
  protected:
   RemoteIO();
   virtual ~RemoteIO();
  public:

   //Fetches filenames from BGQ's persisent memory ramdisk
   bool getFileNames(std::vector<std::string> &filenames) const;
   static bool getFileNames(ProcessSet::const_ptr pset, FileSet &result);

   //Get data as per a stat system call, fill in the FileInfo objects
   bool getFileStatData(FileInfo &fi) const;
   static bool getFileStatData(FileSet &fset);

   //These are whole file reads and produce EventAsyncFileRead callbacks
   bool readFileContents(const FileInfo &fi) const;
   static bool readFileConents(const FileSet &fset);

   //Partial file reads, also produce EventAsyncFileRead callbacks
   bool readFileContents(const FileInfo &fi, Dyninst::Offset offset, size_t read_size);
   static bool readFileConents(const FileSet &fset, Dyninst::Offset offset, size_t read_size);
     
   bool readFileContents(std::string filename, size_t offset, size_t numbytes, unsigned char* &result);
};
#endif

}
}

#endif
