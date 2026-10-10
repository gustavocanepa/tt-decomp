struct S { char pad[0x10]; int unk10; };
extern void func_003FCFD8(int);

void func_0051BC70(S *arg0)
{
    func_003FCFD8(arg0->unk10);
}
