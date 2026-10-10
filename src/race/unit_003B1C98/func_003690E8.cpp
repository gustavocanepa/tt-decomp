extern "C" void func_0040BC48(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D1560;

struct func_003690E8_arg0 {
    char pad0[0x194];
    void *unk194;
};

extern "C" void func_003690E8(struct func_003690E8_arg0 *arg0, int arg1) {
    arg0->unk194 = &D_005D1560;
    func_0040BC48(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
