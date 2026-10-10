struct S { char pad[0x10]; int unk10; };
extern void func_003FCF20(int);

void func_0051A9E8(S *arg0)
{
    func_003FCF20(arg0->unk10);
}
