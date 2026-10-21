
typedef int s32;
typedef unsigned char u8;
s32 func_004E42B0(s32, s32);
s32 func_004E8180(void *);
struct X
{
  void *unk0;
  s32 unk4;
  char pad8[0x12];
  u8 unk1A;
};
struct Y
{
  s32 unk0;
  s32 unk4;
  s32 unk8;
};
s32 func_00575990(void **arg0)
{
  struct X *x;
  struct Y *y;
  s32 flag;
  s32 r;
  s32 n;
  u8 v;
  x = (struct X *) (*arg0);
  v = x->unk1A;
  if (v != 0)
  {
    x->unk1A = (u8) (v | 2);
    flag = 0;
  }
  else
  {
    n = x->unk4;
    if (n != 0)
    {
      y = (struct Y *) x->unk0;
      if (y->unk8 == y->unk4)
      {
        func_004E42B0(n, n);
      }
    }
    flag = 1;
  }
  if (flag == 0)
  {
    return -1;
  }
  r = func_004E8180(((struct X *) (*arg0))->unk0);
  if (r == (-1))
  {
    ;
    ((struct X *) (*arg0))->unk1A = (u8) (((struct X *) (*arg0))->unk1A | 1);
  }
  return r;
}
