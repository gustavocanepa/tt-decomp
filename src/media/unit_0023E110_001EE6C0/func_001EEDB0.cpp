struct S { char pad[0x14]; int unk14; };
extern void func_00266228(int);

void func_001EEDB0(S *arg0)
{
    func_00266228(arg0->unk14);
}
