struct S { char pad[0x10]; int unk10; };
extern void func_003FD100(int);

void func_0051B128(S *arg0)
{
    func_003FD100(arg0->unk10);
}
