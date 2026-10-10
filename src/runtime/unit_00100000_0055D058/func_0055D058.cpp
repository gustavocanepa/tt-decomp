extern "C" void func_0037D460(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D45D0;

struct func_0055D058_arg0 {
    char pad0[0x18];
    void *unk18;
};

extern "C" void func_0055D058(struct func_0055D058_arg0 *arg0, int arg1) {
    arg0->unk18 = &D_005D45D0;
    func_0037D460(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
