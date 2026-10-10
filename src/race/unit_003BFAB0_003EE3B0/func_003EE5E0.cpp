extern "C" void func_00456A00(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D74F8;

struct func_003EE5E0_arg0 {
    char pad0[0x24];
    void *unk24;
};

extern "C" void func_003EE5E0(struct func_003EE5E0_arg0 *arg0, int arg1) {
    arg0->unk24 = &D_005D74F8;
    func_00456A00(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
