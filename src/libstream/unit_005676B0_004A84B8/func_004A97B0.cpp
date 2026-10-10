extern "C" void func_004A9288(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DADB0;

struct func_004A97B0_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void func_004A97B0(struct func_004A97B0_arg0 *arg0, int arg1) {
    arg0->unk4 = &D_005DADB0;
    func_004A9288(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
