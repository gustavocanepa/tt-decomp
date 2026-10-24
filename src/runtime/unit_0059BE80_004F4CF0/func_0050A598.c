/* gcc-softfloat gcc snapshot 2000-10-03: func_0050A598 from float.c, placed at 0x0050a598 by
 * tools/libmatch.py. Third-party code, see THIRD_PARTY.md for its license and origin.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
#define func_005BDF58 func_005BDF58
#define func_005BE508 func_005BE508
#define func_005BE1A0 func_005BE1A0
#define func_005BE250 func_005BE250
#define func_005BD900 func_005BD900
#define func_005BD9B8 func_005BD9B8
#define func_0050A598 func_0050A598
#define func_005BDC18 func_005BDC18
#define func_005BE020 func_005BE020
#define func_005BDC70 func_005BDC70
#define func_005BE120 func_005BE120
#define func_005BE1D0 func_005BE1D0
# 1 "fp-bit.c"
/* This is a software floating point library which can be used instead of
   the floating point routines in libgcc1.c for targets without hardware
   floating point.
   Copyright (C) 1994, 1995, 1996, 1997, 1998,
   2000 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file with other programs, and to distribute
those programs without any restriction coming from the use of this
file.  (The General Public License restrictions do apply in other
respects; for example, they cover modification of the file, and
distribution when not linked into another program.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, func_005AE268 to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */
# 30 "fp-bit.c"

# 1 "fp-bit.h" 1

/* Copyright (C) 2000
   Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, func_005AE268 to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */
# 22 "fp-bit.h"

typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));

typedef int HItype __attribute__ ((mode (HI)));
typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));

typedef unsigned int UHItype __attribute__ ((mode (HI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));

        typedef USItype fractype;
        typedef UHItype halffractype;
        typedef SFtype FLO_type;
        typedef SItype intfrac;

# 157 "fp-bit.h"

# 183 "fp-bit.h"

# 204 "fp-bit.h"
# 223 "fp-bit.h"

typedef enum
{
  CLASS_SNAN,
  CLASS_QNAN,
  CLASS_ZERO,
  CLASS_NUMBER,
  CLASS_INFINITY
} fp_class_type;

typedef struct
{

  fp_class_type class;
  unsigned int sign;
  int normal_exp;

  union
    {
      fractype ll;
      halffractype l[2];
    } fraction;
} fp_number_type;

typedef union
{
  FLO_type value;
  fractype value_raw;

  struct
    {
      fractype fraction:23 __attribute__ ((packed));
      unsigned int exp:8 __attribute__ ((packed));
      unsigned int sign:1 __attribute__ ((packed));
    }
  bits;

# 310 "fp-bit.h"

}
FLO_union_type;

extern FLO_type func_005BD900 (fp_number_type *);

extern void func_005BD9B8 (FLO_union_type *, fp_number_type *);

extern FLO_type func_005BDC18 (FLO_type, FLO_type);
extern FLO_type func_005BDC70 (FLO_type, FLO_type);

extern FLO_type func_005BDCD8 (FLO_type, FLO_type);

extern FLO_type fpdiv (FLO_type, FLO_type);

extern int func_005BDF58 (fp_number_type *, fp_number_type *);

extern SItype func_005BE020 (FLO_type, FLO_type);

extern FLO_type sitofp (SItype);

extern SItype func_005BE120 (FLO_type);

extern USItype func_005BE1D0 (FLO_type);

extern FLO_type __negsf2 (FLO_type);

extern SFtype func_005BE1A0 (fp_class_type, unsigned int, int, USItype);

extern DFtype func_005BE508 (fp_class_type, unsigned int, int, UDItype);

extern DFtype fptodp (SFtype);

# 48 "fp-bit.c" 2

# 68 "fp-bit.c"

# 78 "fp-bit.c"
# 111 "fp-bit.c"

# 158 "fp-bit.c"

__inline__
static int
iszero ( fp_number_type * x)

{
  return x->class == CLASS_ZERO;
}

__inline__
static void
flip_sign ( fp_number_type * x)

{
  x->sign = !x->sign;
}

extern FLO_type func_005BD900 ( fp_number_type * );

FLO_type
func_005BD900 ( fp_number_type * src);

void
func_005BD9B8 (FLO_union_type * src, fp_number_type * dst);

static fp_number_type *
func_0050A598 (fp_number_type * a,
              fp_number_type * b,
              fp_number_type * tmp)

{
  intfrac tfraction;

  int a_normal_exp;
  int b_normal_exp;
  fractype a_fraction;
  fractype b_fraction;

  if (0)
    {
      return a;
    }
  if (0)
    {
      return b;
    }
  if (0)
    {

      if (0 && a->sign != b->sign)
        return 0;
      return a;
    }
  if (0)
    {
      return b;
    }
  if (iszero (b))
    {
      if (iszero (a))
        {
          *tmp = *a;
          tmp->sign = a->sign & b->sign;
          return tmp;
        }
      return a;
    }
  if (iszero (a))
    {
      return b;
    }

  {
    int diff;

    a_normal_exp = a->normal_exp;
    b_normal_exp = b->normal_exp;
    a_fraction = a->fraction.ll;
    b_fraction = b->fraction.ll;

    diff = a_normal_exp - b_normal_exp;

    if (diff < 0)
      diff = -diff;
    if (diff < 32)
      {

        while (a_normal_exp > b_normal_exp)
          {
            b_normal_exp++;
            { b_fraction = (b_fraction & 1) | (b_fraction >> 1); };
          }
        while (b_normal_exp > a_normal_exp)
          {
            a_normal_exp++;
            { a_fraction = (a_fraction & 1) | (a_fraction >> 1); };
          }
      }
    else
      {

        if (a_normal_exp > b_normal_exp)
          {
            b_normal_exp = a_normal_exp;
            b_fraction = 0;
          }
        else
          {
            a_normal_exp = b_normal_exp;
            a_fraction = 0;
          }
      }
  }

  if (a->sign != b->sign)
    {
      if (a->sign)
        {
          tfraction = -a_fraction + b_fraction;
        }
      else
        {
          tfraction = a_fraction - b_fraction;
        }
      if (tfraction >= 0)
        {
          tmp->sign = 0;
          tmp->normal_exp = a_normal_exp;
          tmp->fraction.ll = tfraction;
        }
      else
        {
          tmp->sign = 1;
          tmp->normal_exp = a_normal_exp;
          tmp->fraction.ll = -tfraction;
        }

      while (tmp->fraction.ll < (1LL<<(23+7L)) && tmp->fraction.ll)
        {
          tmp->fraction.ll <<= 1;
          tmp->normal_exp--;
        }
    }
  else
    {
      tmp->sign = a->sign;
      tmp->normal_exp = a_normal_exp;
      tmp->fraction.ll = a_fraction + b_fraction;
    }
  tmp->class = CLASS_NUMBER;

  if (tmp->fraction.ll >= (1LL<<(23+1+7L)))
    {
      { tmp->fraction.ll = (tmp->fraction.ll & 1) | (tmp->fraction.ll >> 1); };
      tmp->normal_exp++;
    }
  return tmp;

}

FLO_type
func_005BDC18 (FLO_type arg_a, FLO_type arg_b);

FLO_type
func_005BDC70 (FLO_type arg_a, FLO_type arg_b);

static __inline__ fp_number_type *
_fpmul_parts ( fp_number_type * a,
               fp_number_type * b,
               fp_number_type * tmp)

{
  fractype low = 0;
  fractype high = 0;

  if (0)
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (0)
    {
      b->sign = a->sign != b->sign;
      return b;
    }
  if (0)
    {
      if (iszero (b))
        return 0;
      a->sign = a->sign != b->sign;
      return a;
    }
  if (0)
    {
      if (iszero (a))
        {
          return 0;
        }
      b->sign = a->sign != b->sign;
      return b;
    }
  if (iszero (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (iszero (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }

  {
# 655 "fp-bit.c"

    {

      DItype answer = (DItype)(a->fraction.ll) * (DItype)(b->fraction.ll);

      high = answer >> 32;
      low = answer;
    }
# 689 "fp-bit.c"

  }

  tmp->normal_exp = a->normal_exp + b->normal_exp;
  tmp->sign = a->sign != b->sign;

  tmp->normal_exp += 2;

  while (high >= (1LL<<(23+1+7L)))
    {
      tmp->normal_exp++;
      if (high & 1)
        {
          low >>= 1;
          low |= 0x80000000L;
        }
      high >>= 1;
    }
  while (high < (1LL<<(23+7L)))
    {
      tmp->normal_exp--;

      high <<= 1;
      if (low & 0x80000000L)
        high |= 1;
      low <<= 1;
    }

# 732 "fp-bit.c"

  if ((high & 0x7f) == 0x40)
    {
      if (high & (1 << 7L))
        {

          high += 0x3f + 1;
        }
      else if (low)
        {

          high += 0x3f + 1;
        }
    }
  tmp->fraction.ll = high;
  tmp->class = CLASS_NUMBER;
  return tmp;
}

FLO_type
func_005BDCD8 (FLO_type arg_a, FLO_type arg_b);

static __inline__ fp_number_type *
_fpdiv_parts (fp_number_type * a,
              fp_number_type * b)

{
  fractype bit;
  fractype numerator;
  fractype denominator;
  fractype quotient;

  if (0)
    {
      return a;
    }
  if (0)
    {
      return b;
    }

  a->sign = a->sign ^ b->sign;

  if (0 || iszero (a))
    {
      if (a->class == b->class)
        return 0;
      return a;
    }

  if (0)
    {
      a->fraction.ll = 0;
      a->normal_exp = 0;
      return a;
    }
  if (iszero (b))
    {
      a->class = CLASS_INFINITY;
      return a;
    }

  {

    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator)
      {

        numerator *= 2;
        a->normal_exp--;
      }
    bit = (1LL<<(23+7L));
    quotient = 0;

    while (bit)
      {
        if (numerator >= denominator)
          {
            quotient |= bit;
            numerator -= denominator;
          }
        bit >>= 1;
        numerator *= 2;
      }

    if ((quotient & 0x7f) == 0x40)
      {
        if (quotient & (1 << 7L))
          {

            quotient += 0x3f + 1;
          }
        else if (numerator)
          {

            quotient += 0x3f + 1;
          }
      }

    a->fraction.ll = quotient;
    return (a);
  }
}

FLO_type
fpdiv (FLO_type arg_a, FLO_type arg_b);

int
func_005BDF58 (fp_number_type * a, fp_number_type * b);

SItype
func_005BE020 (FLO_type arg_a, FLO_type arg_b);

# 1008 "fp-bit.c"

# 1029 "fp-bit.c"

# 1050 "fp-bit.c"

# 1070 "fp-bit.c"

# 1091 "fp-bit.c"

# 1112 "fp-bit.c"

# 1130 "fp-bit.c"

FLO_type
sitofp (SItype arg_a);

FLO_type
usi_to_float (USItype arg_a);

SItype
func_005BE120 (FLO_type arg_a);

USItype
func_005BE1D0 (FLO_type arg_a);

FLO_type
__negsf2 (FLO_type arg_a);

SFtype
func_005BE1A0(fp_class_type class,
             unsigned int sign,
             int exp,
             USItype frac);

DFtype
fptodp (SFtype arg_a);

# 1347 "fp-bit.c"

# 1369 "fp-bit.c"
