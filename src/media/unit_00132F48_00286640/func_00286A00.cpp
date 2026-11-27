
typedef int s32;
typedef float f32;
struct Func002E4390Sub
{
  char pad0[0x134];
  union 
  {
    s32 i;
    f32 f;
  } f10C;
  union 
  {
    s32 i;
    f32 f;
  } f110;
};
struct Func002E4390Obj
{
  char pad0[0x4C];
  struct Func002E4390Sub *sub;
  s32 m18;
  s32 m1C;
  s32 m20;
};
extern void func_00286A00(struct Func002E4390Obj *arg0)
{
  struct Func002E4390Obj *self = arg0;
  s32 a3 = self->m20;
  s32 a1;
  if (a3 == (-1))
  {
    a1 = self->m1C;
    if (a1 == a3)
    {
      self->sub->f10C.i = a1;
      self->sub->f110.i = a1;
      return;
    }
  }
  else
  {
    a1 = self->m1C;
  }
  {
    s32 mx = (a3 < a1) ? (a1) : (a3);
    self->sub->f10C.i = a1;
    self->sub->f110.i = mx;
  }
  {
    s32 n = self->m20 + 1;
    self->m20 = n;
    if ((self->m1C == 0) && (n >= self->m18))
    {
      self->m1C = -1;
      self->m20 = -1;
    }
  }
}
