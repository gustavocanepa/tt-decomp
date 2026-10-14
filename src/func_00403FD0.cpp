
typedef signed char s8;
struct Obj
{
  char pad0[0x10];
  s8 unk10;
  s8 unk11;
  s8 unk12;
  s8 unk13;
  s8 unk14;
  s8 unk15;
  s8 unk16;
  s8 unk17;
  s8 unk18;
  s8 unk19;
};
extern void func_00403FD0(struct Obj *arg0, int arg1)
{
  int v = 1;
  if (arg1)
  {
    v = arg1;
  }
  arg0->unk10 = v;
  arg0->unk13 = 4;
  arg0->unk14 = 0xA;
  arg0->unk15 = 8;
  arg0->unk16 = 0x11;
  arg0->unk17 = 7;
  arg0->unk18 = 2;
  arg0->unk11 = 0;
  arg0->unk12 = 3;
  arg0->unk19 = 3;
}
