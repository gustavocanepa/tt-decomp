extern int D_00598C0C;
extern void *D_007A6410[7];
extern "C" void func_004CEE28(void *p);

extern "C" void func_004C1530(void)
{
    if (D_00598C0C) {
        for (int i = 0; i < 7; i++) {
            if (D_007A6410[i])
                func_004CEE28(D_007A6410[i]);
        }
    }
}
