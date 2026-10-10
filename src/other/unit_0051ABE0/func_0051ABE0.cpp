struct S { char pad[0x10]; int unk10; };
extern void func_003FD4B0(int);

void func_0051ABE0(S *arg0)
{
    func_003FD4B0(arg0->unk10);
}
