struct S { char pad[0x10]; int unk10; };
extern void func_003FD1F8(int);

void func_0051B1D0(S *arg0)
{
    func_003FD1F8(arg0->unk10);
}
