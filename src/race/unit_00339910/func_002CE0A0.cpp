extern "C" void func_0036BE50(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005C90F0;

struct func_002CE0A0_arg0 {
    char pad0[0x20];
    void *unk20;
};

extern "C" void func_002CE0A0(struct func_002CE0A0_arg0 *arg0, int arg1) {
    arg0->unk20 = &D_005C90F0;
    func_0036BE50(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
