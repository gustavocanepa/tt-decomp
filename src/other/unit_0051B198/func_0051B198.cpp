struct S { char pad[0x10]; int unk10; };
extern void func_003FD198(int);

void func_0051B198(S *arg0)
{
    func_003FD198(arg0->unk10);
}
