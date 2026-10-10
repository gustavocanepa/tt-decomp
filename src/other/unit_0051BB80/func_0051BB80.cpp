struct S { char pad[0x10]; int unk10; };
extern void func_003FD440(int);

void func_0051BB80(S *arg0)
{
    func_003FD440(arg0->unk10);
}
