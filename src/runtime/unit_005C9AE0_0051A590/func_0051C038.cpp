struct S { char pad[0x10]; int unk10; };
extern void func_003FCC50(int);

void func_0051C038(S *arg0)
{
    func_003FCC50(arg0->unk10);
}
