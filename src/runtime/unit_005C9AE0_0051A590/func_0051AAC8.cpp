struct S { char pad[0x10]; int unk10; };
extern void func_003FDBA8(int);

void func_0051AAC8(S *arg0)
{
    func_003FDBA8(arg0->unk10);
}
