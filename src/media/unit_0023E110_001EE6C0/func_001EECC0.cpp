struct S { char pad[0x10]; int unk10; };
extern void func_00266440(int);

void func_001EECC0(S *arg0)
{
    func_00266440(arg0->unk10);
}
