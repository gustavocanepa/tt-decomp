struct S { char pad[0x10]; int unk10; };
extern void func_003FD340(int);

void func_0051B2D8(S *arg0)
{
    func_003FD340(arg0->unk10);
}
