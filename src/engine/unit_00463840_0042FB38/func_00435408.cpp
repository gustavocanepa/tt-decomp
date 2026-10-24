
typedef float f32;
typedef int s32;
typedef unsigned int u32;
extern f32 func_00435408(s32 arg0, s32 arg1, u32 arg2)
{
  f32 a = ((f32) ((unsigned char) arg0)) / 100.0f;
  f32 b = ((f32) ((signed char) arg1)) / 100.0f;
  u32 l = arg2 & 1;
  u32 h = arg2 >> 1;
  f32 c;
  if (1)
  {
  }
  arg2 = (s32) arg2;
  if (arg2 >= 0)
  {
    c = (f32) arg2;
  }
  else
  {
    c = 2.0f * ((f32) ((s32) (l | h)));
  }
  return a + (b * (c / 1000.0f));
}
