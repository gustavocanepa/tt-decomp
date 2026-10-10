struct S { char pad[0x10]; int unk10; };
extern void func_003FDB10(int);

void func_0051B6E8(S *arg0)
{
    func_003FDB10(arg0->unk10);
}
