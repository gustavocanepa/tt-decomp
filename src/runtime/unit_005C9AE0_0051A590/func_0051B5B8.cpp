struct S { char pad[0x10]; int unk10; };
extern void func_003FD8A0(int);

void func_0051B5B8(S *arg0)
{
    func_003FD8A0(arg0->unk10);
}
