struct S { char pad[0x18]; int unk18; };
extern void func_0050E1A8(S *);
extern int D_005B42F8;

void func_00216870(S *arg0, int arg1)
{
  arg1 = arg1 & 1;
  arg0->unk18 = (int)&D_005B42F8;
  if (arg1)
  {
    func_0050E1A8(arg0);
    return;
  }
}
