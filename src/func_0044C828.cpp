
typedef struct func_0044C828_arg0 func_0044C828_arg0;
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
void *memcpy(void *, const void *, unsigned int);
s32 func_0044C720(void *, s32);
s32 func_004A4D68();
s32 func_004A4DD8(void *);
s32 func_004F6574(s32, s32, s32, s32);
struct func_0044C828_arg0
{
  char pad0[0x30];
  s32 unk30;
  s32 unk34;
  s32 unk38;
};
void func_0044C828(struct func_0044C828_arg0 *arg0, s32 arg1)
{
  s32 temp_a0;
  s32 temp_a3;
  s32 temp_v0;
  s32 var_v0;
  func_004A4D68();
  temp_v0 = func_0044C720(arg0, arg1);
  temp_a3 = temp_v0 * 0x10;
  if (temp_v0 >= 0)
  {
    var_v0 = arg0->unk38 - 1;
    temp_a0 = arg0->unk30 + temp_a3;
    if (temp_v0 != var_v0)
    {
      func_004F6574(temp_a0, temp_a0 + 0x10, (var_v0 * 0x10) - 0x10, temp_a3);
      ;
    }
    arg0->unk38 = arg0->unk38 - 1;
  }
  func_004A4DD8(arg0);
}
