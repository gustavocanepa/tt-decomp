
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int s128;
typedef unsigned int u128;
s32 func_002F04D8(s32, s32);
s32 func_003053E8(s32, s32, s32);
s32 func_00305CB0(s32 *, s32, s32, s32, s32, s32, u8);
struct func_003A2398_temp_v0
{
  char pad0[0x5D7];
  u8 unk5B7;
};
struct func_003A2398_obj
{
  char pad0[0x928];
  s32 unk928[1];
};
s32 func_003A2398(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
  s32 *new_var2;
  s32 temp_s0;
  s32 temp_v0_2;
  struct func_003A2398_temp_v0 *temp_v0;
  s32 *new_var;
  new_var = arg0;
  temp_v0_2 = 0;
  temp_s0 = *new_var;
  temp_v0 = (struct func_003A2398_temp_v0 *) func_002F04D8((s32) new_var, arg1);
  if (temp_v0->unk5B7 == temp_v0_2)
  {
    new_var2 = ((struct func_003A2398_obj *) temp_s0)->unk928;
    temp_v0_2 = new_var2[arg3];
    if (temp_v0_2 != 0x157529FF)
    {
      func_003053E8(temp_s0, arg1, arg6 - temp_v0_2);
    }
  }
  temp_v0_2 = arg5;
  return func_00305CB0(new_var, arg1, arg2, arg3, temp_v0_2, arg6, temp_v0->unk5B7);
}
