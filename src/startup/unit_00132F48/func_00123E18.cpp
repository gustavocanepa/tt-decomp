struct S { char pad[0x10]; int unk10; };
extern void func_003F6930(int);

void func_00123E18(S *arg0)
{
    func_003F6930(arg0->unk10);
}
