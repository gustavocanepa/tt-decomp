struct S { char pad[0x10]; int unk10; };
extern void func_001FEF08(int);

void func_001E4E60(S *arg0)
{
    func_001FEF08(arg0->unk10);
}
