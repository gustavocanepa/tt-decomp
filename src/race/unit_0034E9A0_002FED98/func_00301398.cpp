
typedef int s32;
typedef unsigned short u16;
typedef signed char s8;
inline int inline_fn(s32 arg0, s32 arg1)
{
  return arg0 | arg1;
}

s32 func_00301398(char *arg0)
{
  u16 *a2 = (u16 *) (arg0 + 0x5DC);
  s8 *a0 = (s8 *) (arg0 + 0x104);
  s32 r;
  s32 v;
  s32 a1;
  s32 a3;
  s32 t0;
  s8 b;
  s32 f;
  v = (s32) (*a2);
  r = 0;
  v = v ^ 1;
  a1 = inline_fn(v, 0x10);
  v = v & 1;
  if (v != 0)
  {
    return r;
  }
  *a2 = (u16) a1;
  r = 1;
  a3 = a1 & 4;
  t0 = a1 & 8;
  if (a3 != 0)
  {
    r = 7;
  }
  b = a0[0x486];
  r = inline_fn(t0, r);
  f = ((s32) b) ^ 1;
  if (f == 0)
  {
    r = r | 0x10;
  }
  return r;
}
