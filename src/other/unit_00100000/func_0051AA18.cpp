struct S { char pad[0x10]; int unk10; };
extern void func_003FD938(int);

void func_0051AA18(S *arg0)
{
    func_003FD938(arg0->unk10);
}
