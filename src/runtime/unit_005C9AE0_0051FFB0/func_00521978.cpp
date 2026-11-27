
typedef unsigned int u32;
typedef unsigned char u8;
struct MT;
extern u32 func_004B2850(struct MT *m);
extern u32 func_004B2BD8(u32 *arg0);
extern void func_00521978(u8 *arg0, u32 arg1, struct MT *arg2, u32 *arg3)
{
  u8 *p;
  u32 n;
  u32 new_var;
  u32 new_var2;
  u32 t;
  p = arg0;
  n = arg1;
  if (n >= 4)
  {
    do
    {
      new_var = func_004B2850(arg2);
      new_var2 = func_004B2BD8(arg3);
      n -= 4;
      t = new_var;
      *((u32 *) p) = ((*((u32 *) p)) + new_var2) ^ t;
      p += 4;
    }
    while (n >= 4);
  }
  if (n != 0)
  {
    do
    {
      n -= 1;
      t = func_004B2850(arg2);
      *p = (u8) (((*p) + func_004B2BD8(arg3)) ^ t);
      p += 1;
    }
    while (n != 0);
  }
}
