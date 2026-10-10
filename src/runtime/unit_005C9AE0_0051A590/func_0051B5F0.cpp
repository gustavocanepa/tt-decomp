struct S { char pad[0x10]; int unk10; };
extern void func_003FD900(int);

void func_0051B5F0(S *arg0)
{
    func_003FD900(arg0->unk10);
}
