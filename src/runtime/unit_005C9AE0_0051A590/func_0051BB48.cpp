struct S { char pad[0x10]; int unk10; };
extern void func_003FD390(int);

void func_0051BB48(S *arg0)
{
    func_003FD390(arg0->unk10);
}
