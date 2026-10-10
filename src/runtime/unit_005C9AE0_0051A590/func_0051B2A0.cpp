struct S { char pad[0x10]; int unk10; };
extern void func_003FD2E0(int);

void func_0051B2A0(S *arg0)
{
    func_003FD2E0(arg0->unk10);
}
