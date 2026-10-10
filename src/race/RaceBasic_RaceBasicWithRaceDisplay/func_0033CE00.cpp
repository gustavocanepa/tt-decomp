extern "C" void func_002CE2F8(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005CCAD8;

struct func_0033CE00_arg0 {
    char pad0[0x64];
    void *unk64;
};

extern "C" void func_0033CE00(struct func_0033CE00_arg0 *arg0, int arg1) {
    arg0->unk64 = &D_005CCAD8;
    func_002CE2F8(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
