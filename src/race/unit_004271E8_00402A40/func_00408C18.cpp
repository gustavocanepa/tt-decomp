
typedef int s32;
extern s32 func_0040D3D8(char *self, s32 v);
extern s32 func_00408C18(char *arg0, s32 arg1)
{
  s32 p = ((s32) arg0) + 8;
  s32 cur = p;
  s32 n = 0;
  s32 v;
  s32 new_var;
  do
  {
    new_var = func_0040D3D8((char *) cur, arg1);
    p += 0x190;
    v = new_var;
    if (v == 0)
    {
      return v;
    }
    n++;
    cur = p;
  }
  while (n < 3);
  return 1;
}
