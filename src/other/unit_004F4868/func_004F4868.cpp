struct S { char pad[0x18]; int unk18; };
extern void func_0050E1A8(S *);
extern int D_005DB6C0;

void func_004F4868(S *arg0, int arg1)
{
  arg1 = arg1 & 1;
  arg0->unk18 = (int)&D_005DB6C0;
  if (arg1)
  {
    func_0050E1A8(arg0);
    return;
  }
}
