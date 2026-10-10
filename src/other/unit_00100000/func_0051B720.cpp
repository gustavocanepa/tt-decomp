struct S { char pad[0x10]; int unk10; };
extern void func_003FDB70(int);

void func_0051B720(S *arg0)
{
    func_003FDB70(arg0->unk10);
}
