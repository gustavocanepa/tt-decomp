extern "C" void func_00554880(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005CDF18;

struct func_0033E7B8_arg0 {
    char pad0[0x134];
    void *unk134;
};

extern "C" void func_0033E7B8(struct func_0033E7B8_arg0 *arg0, int arg1) {
    arg0->unk134 = &D_005CDF18;
    func_00554880(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
