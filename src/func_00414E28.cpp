
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 func_00414DC8(const u8 *buf, unsigned int bit);
extern s32 func_00414E28(const u8 *arg0, unsigned int arg1, u32 arg2)
{
  s32 acc;
  const u8 *buf;
  u32 var_s1;
  s32 var_s2;
  u32 var_s0;
  u32 temp_a1;
  s32 temp_v0;
  acc = 0;
  buf = arg0;
  var_s1 = arg2;
  var_s2 = 0;
  var_s0 = arg1;
  if (var_s1 >= 8U)
  {
    do
    {
      temp_a1 = var_s0;
      temp_v0 = func_00414DC8(buf, temp_a1) << var_s2;
      var_s0 += 8;
      var_s1 -= 8;
      var_s2 += 8;
      acc |= temp_v0;
    }
    while (var_s1 >= 8U);
  }
  if (var_s1 != 0)
  {
    acc |= ((func_00414DC8(buf, var_s0) & ((1 << var_s1) - 1)) & 0xFF) << var_s2;
  }
  return acc;
}
