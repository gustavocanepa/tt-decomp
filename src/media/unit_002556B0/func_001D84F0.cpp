
typedef int s32;
typedef unsigned char u8;
typedef signed char s8;
extern s32 func_002C0F28(s32);
extern void *func_001D84F0(s8 *arg0)
{
  s32 *h = (s32 *) (arg0 + 0x30);
  s32 var_s2;
  unsigned int var_s1;
  void *var_v0;
  var_s2 = 0;
  if (((*h) == 0) || (func_002C0F28(*h) == 0))
  {
    var_s2 = 1;
  }
  var_v0 = 0;
  if (var_s2 == 0)
  {
    var_v0 = (void *) (*h);
  }
 do { if (var_v0 == 0) { return arg0; } var_s1 = 0; } while (0);
  if (((*h) == 0) || (func_002C0F28(*h) == 0))
  {
    var_s1 = 1;
  }
  if (var_s1 == 0)
  {
    return (void *) (*h);
  }
  return 0;
}
