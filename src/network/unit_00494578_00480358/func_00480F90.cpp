extern "C" void func_004802F0(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DA940;

struct func_00480F90_arg0 {
    char pad0[0xA4];
    void *unkA4;
};

extern "C" void func_00480F90(struct func_00480F90_arg0 *arg0, int arg1) {
    arg0->unkA4 = &D_005DA940;
    func_004802F0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
