extern "C" void func_001DC020(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005AEDB0;

struct func_00524998_arg0 {
    char pad0[0x18];
    void *unk18;
};

extern "C" void func_00524998(struct func_00524998_arg0 *arg0, int arg1) {
    arg0->unk18 = &D_005AEDB0;
    func_001DC020(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
