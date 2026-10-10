struct S { char pad[0xC]; int unkC; };
extern int D_00598424;
extern void func_004CDB68(int);

void func_004BDB58(S *arg0)
{
    if (D_00598424 != 0) {
        func_004CDB68(arg0->unkC);
    }
}
