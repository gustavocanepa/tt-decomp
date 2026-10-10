struct S { char pad[0x10]; int unk10; };
extern void func_001FEF90(int);

void func_001E4E80(S *arg0)
{
    func_001FEF90(arg0->unk10);
}
