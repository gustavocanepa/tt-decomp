extern "C" void func_0037FB98(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D4500;

struct func_0037EF60_arg0 {
    char pad0[0x18];
    void *unk18;
};

extern "C" void func_0037EF60(struct func_0037EF60_arg0 *arg0, int arg1) {
    arg0->unk18 = &D_005D4500;
    func_0037FB98(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
