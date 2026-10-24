
typedef int s32;
s32 func_0040CDE8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  s32 small;
  s32 num;
  small = arg3 < 2;
 do { arg3 = arg3 - 1; arg2 = arg2 - arg1; arg4 = arg4 - 1; num = arg2 * arg4; if (small) { return arg1; } } while (0);
  return arg1 + (num / arg3);
}
