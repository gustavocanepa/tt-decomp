struct S { char pad[0xC]; int unkC; };
extern int D_00598424;
extern void func_004CDDF8(int);

void func_004BDB30(S *arg0)
{
    if (D_00598424 != 0) {
        func_004CDDF8(arg0->unkC);
    }
}
