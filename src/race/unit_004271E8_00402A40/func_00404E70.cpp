extern unsigned short D_005FB500[];
extern "C" void func_003FEF48(void *, int, int, int);
extern "C" short func_004C99C0(void *, int);
extern "C" void func_00404E70(int a0, void *a1, void *a2, signed char *a3) {
    int i = 0;
    do {
        int t = func_004C99C0(a2, i + 0x18);
        int w = t;
        unsigned short *q = D_005FB500 + w;
        w = -w;
        w = w << 2;
        if (i != 0) w = *q;
        func_003FEF48(a1, a0, a3[i], w);
        i++;
    } while (i < 3);
}
