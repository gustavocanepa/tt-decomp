
typedef int s32;
typedef short s16;
typedef signed char s8;
struct func_00482368_arg0
{
  char pad0[0x85C];
  s32 unk858;
};
extern s32 func_00482368(void *arg0)
{
  char *temp;
  char *e;
  char *p;
  s32 key;
  s32 count;
  s32 sum;
  s32 new_var;
  s32 n;
  s8 b;
  temp = ((char *) arg0) + ((1 - ((struct func_00482368_arg0 *) arg0)->unk858) * 0x41C);
  e = temp + 0x24;
  count = *((s32 *) (e + 0x214));
  sum = 0;
  if (count > 0)
  {
    key = *((s32 *) e);
    n = count;
    do
    {
      new_var = key;
      p = e + 0x218;
      if (new_var == 0)
      {
        b = *((s8 *) p);
        if (b == 6)
        {
          sum += (*((s16 *) (p + 6))) - (*((s16 *) (p + 4)));
        }
      }
      else
        if (new_var == 1)
      {
        b = *((s8 *) p);
        if ((b == 6) || (b == new_var))
        {
          sum += (*((s16 *) (p + 6))) - (*((s16 *) (p + 4)));
        }
      }
      else
        if (new_var == 2)
      {
        b = *((s8 *) p);
        if (((((b == 6) || (b == new_var)) || (b == 3)) || (b == 4)) || (b == 5))
        {
          sum += (*((s16 *) (p + 6))) - (*((s16 *) (p + 4)));
        }
      }
      n--;
      e += 8;
    }
    while (n != 0);
  }
  return sum;
}
