struct S { char pad[0x10]; int unk10; };
extern void func_002B1090(int);

void func_002A39C0(S *arg0)
{
    func_002B1090(arg0->unk10);
}
