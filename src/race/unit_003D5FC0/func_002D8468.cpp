
typedef float f32;
typedef int s32;
struct func_002D8468_arg0
{
  char pad0[0x88];
  f32 x88;
  f32 x8C;
  char pad90[0x14];
  union 
  {
    s32 i;
    f32 f;
  } xA4;
  s32 xA8;
};
void func_002D8468(struct func_002D8468_arg0 *arg0, f32 fparg0)
{
  f32 temp_f1;
  f32 temp_f12;
  s32 t4;
  temp_f1 = arg0->x88 - fparg0;
  arg0->x88 = temp_f1;
  if (temp_f1 < 0.0f)
  {
    arg0->xA4.i = (arg0->xA4.i & 0xFF00FFFF) | 0x10000;
    arg0->x88 = temp_f1 + 0.2f;
  }
  temp_f12 = arg0->x8C - fparg0;
  arg0->x8C = temp_f12;
  if (temp_f12 < 0.0f)
  {
    t4 = (arg0->xA4.i & 0xFFFFFF) | 0x01000000;
    arg0->x8C = temp_f12 + 1.0f;
    arg0->xA4.i = t4;
    arg0->xA8 = (arg0->xA8 & (~0xFF)) | 1;
  }
}
