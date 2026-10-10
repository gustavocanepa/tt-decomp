struct S { char pad[0x10]; int unk10; };
extern void func_003FD510(int);

void func_0051AFD0(S *arg0)
{
    func_003FD510(arg0->unk10);
}
