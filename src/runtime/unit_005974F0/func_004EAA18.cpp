/* libio floatconv.c quorem; public body with the earlier cmp helper declared throw().
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
/* 
Copyright (C) 1993, 1994 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, func_005AE268 to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

/****************************************************************
 *
 * The author of this software is David M. Gay.
 *
 * Copyright (c) 1991 by AT&T.
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 *
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHOR NOR AT&T MAKES ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 *
 ***************************************************************/
typedef int _G_int32_t;
typedef unsigned int unsigned32;
struct Bigint {
    Bigint *next;
    int k, maxwds;
    short on_stack, sign;
    int wds;
    unsigned32 x[8];
};
#define Sign_Extend(a,b)
#define Storeinc(a,b,c) (((unsigned short *)a)[1] = (unsigned short)b, ((unsigned short *)a)[0] = (unsigned short)c, a++)
extern "C" int func_004E9450(Bigint *, Bigint *) throw();
#define cmp func_004E9450
extern "C" int func_004EAA18(Bigint *b, Bigint *S)
{
        int n;
        _G_int32_t borrow, y;
        unsigned32 carry, q, ys;
        unsigned32 *bx, *bxe, *sx, *sxe;
        _G_int32_t z;
        unsigned32 si, zs;

        n = S->wds;
#ifdef DEBUG
         if (b->wds > n)
               Bug("oversize b in quorem");
#endif
        if (b->wds < n)
                return 0;
        sx = S->x;
        sxe = sx + --n;
        bx = b->x;
        bxe = bx + n;
        q = *bxe / (*sxe + 1);  
#ifdef DEBUG
         if (q > 9)
               Bug("oversized quotient in quorem");
#endif
        if (q) {
                borrow = 0;
                carry = 0;
                do {
                        si = *sx++;
                        ys = (si & 0xffff) * q + carry;
                        zs = (si >> 16) * q + (ys >> 16);
                        carry = zs >> 16;
                        y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
                        borrow = y >> 16;
                        Sign_Extend(borrow, y);
                        z = (*bx >> 16) - (zs & 0xffff) + borrow;
                        borrow = z >> 16;
                        Sign_Extend(borrow, z);
                        Storeinc(bx, z, y);
                        }
                        while(sx <= sxe);
                if (!*bxe) {
                        bx = b->x;
                        while(--bxe > bx && !*bxe)
                                --n;
                        b->wds = n;
                        }
                }
        if (cmp(b, S) >= 0) {
                q++;
                borrow = 0;
                carry = 0;
                bx = b->x;
                sx = S->x;
                do {
                        si = *sx++;
                        ys = (si & 0xffff) + carry;
                        zs = (si >> 16) + (ys >> 16);
                        carry = zs >> 16;
                        y = (*bx & 0xffff) - (ys & 0xffff) + borrow;
                        borrow = y >> 16;
                        Sign_Extend(borrow, y);
                        z = (*bx >> 16) - (zs & 0xffff) + borrow;
                        borrow = z >> 16;
                        Sign_Extend(borrow, z);
                        Storeinc(bx, z, y);
                        }
                        while(sx <= sxe);
                bx = b->x;
                bxe = bx + n;
                if (!*bxe) {
                        while(--bxe > bx && !*bxe)
                                --n;
                        b->wds = n;
                        }
                }
        return q;
        }
