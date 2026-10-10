struct S { char pad[0x18]; int unk18; };
extern void func_0050E1A8(S *);
extern int D_005D44A0;

void func_0055CF88(S *arg0, int arg1)
{
  arg1 = arg1 & 1;
  arg0->unk18 = (int)&D_005D44A0;
  if (arg1)
  {
    func_0050E1A8(arg0);
    return;
  }
}
