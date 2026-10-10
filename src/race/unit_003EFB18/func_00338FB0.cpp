extern "C" void func_0037A840(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005CBC28;

struct func_00338FB0_arg0 {
    char pad0[0x134];
    void *unk134;
};

extern "C" void func_00338FB0(struct func_00338FB0_arg0 *arg0, int arg1) {
    arg0->unk134 = &D_005CBC28;
    func_0037A840(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
