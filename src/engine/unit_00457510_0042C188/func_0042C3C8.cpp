struct Buffers_004610E8 {
    int m0;
    char pad4[0x8];
    void *mC;
    void *m10;
};

extern "C" Buffers_004610E8 D_0076A008;
extern "C" void func_004C6D90(int a, int b);
extern "C" void func_004A45D0(void *p);

extern "C" void func_0042C3C8(void)
{
    func_004C6D90(1, 0);
    if (D_0076A008.m10) {
        func_004A45D0(D_0076A008.m10);
        D_0076A008.m10 = 0;
    }
    if (D_0076A008.mC) {
        func_004A45D0(D_0076A008.mC);
        D_0076A008.mC = 0;
    }
    D_0076A008.m0 = -1;
}
