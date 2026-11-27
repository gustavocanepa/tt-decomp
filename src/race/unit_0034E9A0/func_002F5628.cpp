
typedef int s32;
typedef float f32;
typedef unsigned char u8;
struct func_002F55A0_Obj;
struct S;
extern f32 func_002F55A0(struct func_002F55A0_Obj *self);
extern s32 func_0039F070(struct S *arg0);
inline int inline_fn(s32 arg0)
{
  return arg0 >= 2;
}

extern f32 func_002F5628(char *arg0)
{
  s32 base = *((s32 *) (arg0 + 0x10));
  char *self = arg0 + 0x104;
  s32 s1 = base + 0x240;
  f32 f20 = func_002F55A0((struct func_002F55A0_Obj *) arg0);
  s32 idx = *((u8 *) (self + 0x540));
  if (func_0039F070((struct S *) s1) != 0)
  {
    idx = (inline_fn(idx)) ? (1) : (idx);
  }
  f32 v = *((f32 *) (((((s32) idx) << 2) + s1) + 0x40));
  f20 = f20 * v;
  if (f20 <= 0.0f)
  {
    f20 = 0.0f;
  }
  return f20;
}
