extern "C" void func_001AF878(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005ADB10;

struct func_00522808_arg0 {
    char pad0[0x5C];
    void *unk5C;
};

extern "C" void func_00522808(struct func_00522808_arg0 *arg0, int arg1) {
    arg0->unk5C = &D_005ADB10;
    func_001AF878(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
