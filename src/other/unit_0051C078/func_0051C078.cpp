struct S { char pad[0x10]; int unk10; };
extern void func_003FCE58(int);

void func_0051C078(S *arg0)
{
    func_003FCE58(arg0->unk10);
}
