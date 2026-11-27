/* compiler: ee-gcc2.96-exceptions */
/* gcc-exception gcc snapshot 2000-10-03 (old C++ ABI): operatornew[]() (func_0050E130) from new2.cc, placed at 0x0050e130 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#define L_op_new
#define L_op_vnew
// Boilerplate support routines for -*- C++ -*- dynamic memory management.
// Copyright (C) 1997, 1998, 1999, 2000 Free Software Foundation

// This file is part of GNU CC.

// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.

// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// The -*- C++ -*- dynamic memory management header.
// Copyright (C) 1994, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#ifndef __NEW__
#define __NEW__

#pragma interface "new"
#ifndef GT4_RUNTIME_STDDEF
#define GT4_RUNTIME_STDDEF
typedef unsigned int size_t;
typedef int ptrdiff_t;
#define NULL 0
#endif

// Exception Handling support header for -*- C++ -*-
// Copyright (C) 1995, 1996, 1997, 1998, 2000 Free Software Foundation

// This file is part of GNU CC.
//
// GNU CC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// GNU CC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU CC; see the file COPYING.  If not, func_005AE268 to
// the Free Software Foundation, 59 Temple Place - Suite 330,
// Boston, MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#ifndef __EXCEPTION__
#define __EXCEPTION__

#pragma interface "exception"

extern "C++" {

namespace std {

class exception {
public:
  exception () { }
  virtual ~exception () { }
  virtual const char* what () const;
};

class bad_exception : public exception {
public:
  bad_exception () { }
  virtual ~bad_exception () { }
};

typedef void (*terminate_handler) ();
typedef void (*unexpected_handler) ();

terminate_handler set_terminate (terminate_handler);
void terminate () __attribute__ ((__noreturn__));
unexpected_handler set_unexpected (unexpected_handler);
void unexpected () __attribute__ ((__noreturn__));
bool uncaught_exception ();

}

}

#endif

extern "C++" {

namespace std {

  class bad_alloc : public exception {
  public:
    virtual ~bad_alloc();
    virtual const char* what() const throw() { return "bad_alloc"; }
  };

  struct nothrow_t {};
  extern const nothrow_t nothrow;
  typedef void (*new_handler)();
  new_handler set_new_handler (new_handler);

}

void *operator new (size_t) throw (std::bad_alloc);
void *operator new[] (size_t) throw (std::bad_alloc);
void operator delete (void *) throw();
void operator delete[] (void *) throw();
void *operator new (size_t, const std::nothrow_t&) throw();
void *operator new[] (size_t, const std::nothrow_t&) throw();
void operator delete (void *, const std::nothrow_t&) throw();
void operator delete[] (void *, const std::nothrow_t&) throw();

inline void *operator new(size_t, void *place) throw()
{ return place; }

inline void *operator new[](size_t, void *place) throw()
{ return place; }
}

#endif

extern "C" void free (void *);

#define WEAK(x) \
  x __attribute__ ((weak)); \
  x

#ifdef L_op_vnew

  void * operator new[] (size_t sz) throw (std::bad_alloc) __attribute__ ((weak));

  void * operator new[] (size_t sz) throw (std::bad_alloc)

{
  return ::operator new(sz);
}
#endif
