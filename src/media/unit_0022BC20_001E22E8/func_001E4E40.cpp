struct S { char pad[0x10]; int unk10; };
extern void func_001FEEA8(int);

void func_001E4E40(S *arg0)
{
    func_001FEEA8(arg0->unk10);
}
