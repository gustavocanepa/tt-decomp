
typedef int s32;
typedef unsigned int u32;
extern s32 func_004A8368(const char *s);
extern s32 func_00281178(s32 unused, const char *s, s32 *out)
{
  s32 len;
  s32 i;
  s32 sum;
  const char *p;
  s32 c;
  s32 t;
  if (s == 0)
  {
    return 0;
  }
  len = func_004A8368(s);
  sum = 0;
  p = s;
  for (i = 0; i < len; i++)
  {
    c = *p;
    p++;
    if ((c != 0x20) && (c != 9))
    {
      if (((u32) (c - 0x30)) >= 10u)
      {
        return 0;
      }
      t = sum * 10;
      sum = t;
      sum = (sum + c) - 0x30;
    }
  }

  *out = sum;
  return 1;
}
