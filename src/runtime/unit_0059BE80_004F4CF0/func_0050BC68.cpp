/* licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* Subroutines needed for unwinding DWARF 2 format stack frame info
   for exception handling.  */
/* Compile this one with gcc.  */
/* Copyright (C) 1997, 1998, 1999, 2000 Free Software Foundation, Inc.
   Contributed by Jason Merrill <jason@cygnus.com>.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, func_005AE268 to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

extern "C" {
struct dwarf_fde { unsigned int length; int CIE_delta; void *pc_begin; unsigned int pc_range; };
typedef dwarf_fde fde;
struct object { void *pc_begin; void *pc_end; fde *fde_begin; fde **fde_array; unsigned int count; object *next; };
extern object *D_00793388;
extern int D_005A319C;
int func_004FA860(int);
int func_004FA840(int);
void func_0050BB00(object *) throw();
fde *func_0050BAA8(fde *, void *);
}
#define D_00793388 D_00793388
#define D_005A319C D_005A319C
#define func_0050BB00 func_0050BB00
#define func_0050BAA8 func_0050BAA8
typedef unsigned int size_t;
inline void init_object_mutex_once() {}
inline int __gthread_mutex_lock(int *p) { return func_004FA860(*p); }
inline int __gthread_mutex_unlock(int *p) { return func_004FA840(*p); }
extern "C" {
fde *
func_0050BC68 (void *pc)
{
  struct object *ob;
  size_t lo, hi;

  init_object_mutex_once ();
  __gthread_mutex_lock (&D_005A319C);

  /* Linear search through the D_00793388, to find the one containing the pc. */
  for (ob = D_00793388; ob; ob = ob->next)
    {
      if (ob->pc_begin == 0)
	func_0050BB00 (ob);
      if (pc >= ob->pc_begin && pc < ob->pc_end)
	break;
    }

  if (ob == 0)
    {
      __gthread_mutex_unlock (&D_005A319C);
      return 0;
    }

  if (!ob->fde_array || (void *)ob->fde_array == (void *)ob->fde_begin)
    func_0050BB00 (ob);

  if (ob->fde_array && (void *)ob->fde_array != (void *)ob->fde_begin)
    {
      __gthread_mutex_unlock (&D_005A319C);
      
      /* Standard binary search algorithm.  */
      for (lo = 0, hi = ob->count; lo < hi; )
	{
	  size_t i = (lo + hi) / 2;
	  fde *f = ob->fde_array[i];

	  if (pc < f->pc_begin)
	    hi = i;
	  else if (pc >= (char *)f->pc_begin + f->pc_range)
	    lo = i + 1;
	  else
	    return f;
	}
    }
  else
    {
      /* Long slow labourious linear search, cos we've no memory. */
      fde *f;
      
      if (ob->fde_array)
	{
	  fde **p = ob->fde_array;
	  
	  do
	    {
	      f = func_0050BAA8 (*p, pc);
	      if (f)
		break;
	      p++;
	    }
	  while (*p);
	}
      else
	f = func_0050BAA8 (ob->fde_begin, pc);
      __gthread_mutex_unlock (&D_005A319C);
      return f;
    }
  return 0;
}


}
