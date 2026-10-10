struct S { char pad[0x3E8]; int unkC; };
extern int D_00598410;
extern void func_004BDB30(int);

void func_004BCD48(S *arg0)
{
    if (D_00598410 != 0) {
        func_004BDB30(arg0->unkC);
    }
}
