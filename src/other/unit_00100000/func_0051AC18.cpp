struct S { char pad[0x10]; int unk10; };
extern void func_003FCEE8(int);

void func_0051AC18(S *arg0)
{
    func_003FCEE8(arg0->unk10);
}
