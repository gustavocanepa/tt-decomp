struct S { char pad[0x10]; int unk10; };
extern void func_001FEE48(int);

void func_001E4E20(S *arg0)
{
    func_001FEE48(arg0->unk10);
}
