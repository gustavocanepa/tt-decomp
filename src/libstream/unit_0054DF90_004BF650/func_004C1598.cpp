extern int D_00598C0C;
extern void *D_007A6410[7];
extern "C" void func_004CEE68(void *p);
extern "C" void func_004C1700(int h);

extern "C" void func_004C1598(void)
{
    if (D_00598C0C) {
        for (int i = 0; i < 7; i++) {
            if (D_007A6410[i])
                func_004CEE68(D_007A6410[i]);
        }
        func_004C1700(D_00598C0C);
    }
}
