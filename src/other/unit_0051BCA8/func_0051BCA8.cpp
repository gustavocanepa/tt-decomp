struct S { char pad[0x10]; int unk10; };
extern void func_003FD038(int);

void func_0051BCA8(S *arg0)
{
    func_003FD038(arg0->unk10);
}
