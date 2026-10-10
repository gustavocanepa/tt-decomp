extern "C" void func_0019B480(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005AD0C8;

struct func_00520118_arg0 {
    char pad0[0x4C];
    void *unk4C;
};

extern "C" void func_00520118(struct func_00520118_arg0 *arg0, int arg1) {
    arg0->unk4C = &D_005AD0C8;
    func_0019B480(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
