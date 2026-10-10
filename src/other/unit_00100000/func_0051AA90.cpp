struct S { char pad[0x10]; int unk10; };
extern void func_003FD588(int);

void func_0051AA90(S *arg0)
{
    func_003FD588(arg0->unk10);
}
