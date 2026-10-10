extern "C" void func_001AF878(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005ADC48;

struct func_00522B30_arg0 {
    char pad0[0x5C];
    void *unk5C;
};

extern "C" void func_00522B30(struct func_00522B30_arg0 *arg0, int arg1) {
    arg0->unk5C = &D_005ADC48;
    func_001AF878(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
