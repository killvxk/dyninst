/*
 * Copyright (c) 1996 Barton P. Miller
 * 
 * We provide the Paradyn Parallel Performance Tools (below
 * described as Paradyn") on an AS IS basis, and do not warrant its
 * validity or performance.  We reserve the right to update, modify,
 * or discontinue this software at any time.  We shall have no
 * obligation to supply such updates or modifications or any other
 * form of support to you.
 * 
 * This license is for research uses.  For such uses, there is no
 * charge. We define "research use" to mean you may freely use it
 * inside your organization for whatever purposes you see fit. But you
 * may not re-distribute Paradyn or parts of Paradyn, in any form
 * source or binary (including derivatives), electronic or otherwise,
 * to any other organization or entity without our permission.
 * 
 * (for other uses, please contact us at paradyn@cs.wisc.edu)
 * 
 * All warranties, including without limitation, any warranty of
 * merchantability or fitness for a particular purpose, are hereby
 * excluded.
 * 
 * By your use of Paradyn, you understand and agree that we (or any
 * other person or entity with proprietary rights in Paradyn) are
 * under no obligation to provide either maintenance services,
 * update services, notices of latent defects, or correction of
 * defects for Paradyn.
 * 
 * Even if advised of the possibility of such damages, under no
 * circumstances shall we (or any other person or entity with
 * proprietary rights in the software licensed hereunder) be liable
 * to you or any third party for direct, indirect, or consequential
 * damages of any character regardless of type of action, including,
 * without limitation, loss of profits, loss of use, loss of good
 * will, or computer failure or malfunction.  You agree to indemnify
 * us (and any other person or entity with proprietary rights in the
 * software licensed hereunder) for any and all liability it may
 * incur to third parties resulting from your use of Paradyn.
 */

/************************************************************************
 * Pair.h: definition of pairs for dictionaries and sets.
************************************************************************/

#if defined(external_templates)
#pragma interface
#endif

#if !defined(_Pair_h_)
#define _Pair_h_

#ifdef USE_STL_VECTOR
#include <stl.h>
#else

/************************************************************************
 * template<class T1, class T2> struct pair
************************************************************************/

// Note that paired classes must provide operator== and operator<

template<class T1, class T2>
struct pair {
 public: //needed so nt build doesn't think members are private
  T1 first;
  T2 second;

  bool operator==(const pair<T1, T2>& p) {
    return (first == p.first) && (second == p.second); 
  }
  bool operator!=(const pair<T1, T2>& p) {
    return !((first == p.first) && (second == p.second));
  }
  /*
  bool operator<(const pair<T1, T2>& p) { 
    return (first < p.first) || (!(p.first < first) && second < p.second); 
  }
  bool operator>(const pair<T1, T2>& p) {
    return (p.first < first) || (!(first < p.first) && p.second < second);
  }
  */
  pair () : first(), second()                                    {}
  pair (const T1& k) : first(k), second(0)                       {}
  pair (const T1& k, const T2& v) : first(k), second(v)          {}
  pair(const pair<T1, T2>& p) : first(p.first), second(p.second) {}
};

template <class T1, class T2>
pair<T1, T2> make_pair(const T1& x, const T2& y)
{
  return pair<T1, T2>(x, y);
}

#endif

#endif /* !defined(_Pair_h_) */
