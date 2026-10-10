struct S { char pad[0x14]; int unk14; };
extern void func_00266418(int);

void func_001EED90(S *arg0)
{
    func_00266418(arg0->unk14);
}
