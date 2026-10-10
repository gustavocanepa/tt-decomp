struct Buffers_00461150 {
    char pad0[0xC];
    void *mC;
    void *m10;
};

extern "C" Buffers_00461150 D_0076A008;
extern "C" void func_0042C3C8(void);
extern "C" void *func_004AE6D8(int size);

extern "C" void func_0042C430(void) {
    func_0042C3C8();

    if (D_0076A008.m10 == 0) {
        D_0076A008.m10 = func_004AE6D8(0x19000);
    }
    if (D_0076A008.mC == 0) {
        D_0076A008.mC = func_004AE6D8(0x2800);
    }
}
