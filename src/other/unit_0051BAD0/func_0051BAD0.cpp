struct S { char pad[0x10]; int unk10; };
extern void func_003FD9F0(int);

void func_0051BAD0(S *arg0)
{
    func_003FD9F0(arg0->unk10);
}
