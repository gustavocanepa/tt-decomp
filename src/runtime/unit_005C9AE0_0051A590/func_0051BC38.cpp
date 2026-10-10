struct S { char pad[0x10]; int unk10; };
extern void func_003FCF78(int);

void func_0051BC38(S *arg0)
{
    func_003FCF78(arg0->unk10);
}
