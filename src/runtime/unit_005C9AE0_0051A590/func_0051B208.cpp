struct S { char pad[0x10]; int unk10; };
extern void func_003FD258(int);

void func_0051B208(S *arg0)
{
    func_003FD258(arg0->unk10);
}
