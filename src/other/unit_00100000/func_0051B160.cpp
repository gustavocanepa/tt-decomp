struct S { char pad[0x10]; int unk10; };
extern void func_003FD140(int);

void func_0051B160(S *arg0)
{
    func_003FD140(arg0->unk10);
}
