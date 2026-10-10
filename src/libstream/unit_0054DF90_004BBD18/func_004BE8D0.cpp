extern "C" void func_004F4500(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DB100;

struct func_004BE8D0_arg0 {
    char pad0[0x38];
    void *unk38;
};

extern "C" void func_004BE8D0(struct func_004BE8D0_arg0 *arg0, int arg1) {
    arg0->unk38 = &D_005DB100;
    func_004F4500(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
