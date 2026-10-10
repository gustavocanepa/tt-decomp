extern "C" void func_0038E308(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D0DD0;

struct func_005579E0_arg0 {
    char pad0[0x14];
    void *unk14;
};

extern "C" void func_005579E0(struct func_005579E0_arg0 *arg0, int arg1) {
    arg0->unk14 = &D_005D0DD0;
    func_0038E308(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
