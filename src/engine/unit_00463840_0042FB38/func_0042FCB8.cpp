
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;
extern s32 func_002F0D10(char *c);
extern void func_0042FCB8(char *arg0, s32 arg1)
{
  char *s0 = arg0 + 0x104;
  char *s1 = arg0 + 0x14;
  u8 v = *((u8 *) (s0 + 0x486));
  char *s2 = *((char **) (arg0 + 4));
  s32 a1;
  if (!(((u32) (v - 1)) < 2))
  {
    a1 = 0;
  }
  else
  {
    s32 c = func_002F0D10(s2);
    a1 = 0;
    if (c == 0)
    {
      if (!(0x1.0AAAA8p+3f <= (*((f32 *) (s0 + 0x55C)))))
      {
        if ((*((u8 *) (s0 + 0x487))) == 0)
        {
          a1 = arg1 != 0;
        }
      }
    }
  }
  if (a1 == 0)
  {
    *((u8 *) (s1 + 0x1A)) = 1;
  }
  if ((*((u8 *) (s1 + 0x1A))) == 0)
  {
    *((u8 *) (s1 + 0x1A)) = *((u8 *) (s2 + 0x20A3B));
  }
}
