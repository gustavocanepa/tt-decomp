struct S { char pad[0x10]; int unk10; };
extern void func_003FD990(int);

void func_0051B3D0(S *arg0)
{
    func_003FD990(arg0->unk10);
}
