
void func_004A45D0(int arg0);
char *func_00509240(void);
void func_005096E8(int arg0)
{
  char *base = func_00509240();
  int off = arg0 - ((int) base);
  int idx = off - 0x10;
  if (((unsigned) idx) < 0xC0u)
  {
    int bit = 1 << (idx / 16);
    int v = *((int *) (base + 0xD0));
    if (arg0)
    {
      v ^= bit;
      bit <<= 1;
    }
    else
    {
      v ^= bit;
      bit <<= 1;
    }
    while (v & bit)
    {
      v ^= bit;
      bit <<= 1;
    }

    *((int *) (base + 0xD0)) = v;
    return;
  }
  return func_004A45D0(arg0);
}
