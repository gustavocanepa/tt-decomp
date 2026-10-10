extern "C" void func_00404F60(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D96B0;

struct func_004046C0_arg0 {
    char pad0[0xC];
    void *unkC;
};

extern "C" void func_004046C0(struct func_004046C0_arg0 *arg0, int arg1) {
    arg0->unkC = &D_005D96B0;
    func_00404F60(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
