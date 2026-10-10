struct S { char pad[0x10]; int unk10; };
extern void func_003FDAB0(int);

void func_0051B460(S *arg0)
{
    func_003FDAB0(arg0->unk10);
}
