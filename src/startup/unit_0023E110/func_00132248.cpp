struct S { char pad[0x14]; int unk14; };
extern void func_004060E8(int);

void func_00132248(S *arg0)
{
    func_004060E8(arg0->unk14);
}
