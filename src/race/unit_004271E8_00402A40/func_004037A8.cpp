extern "C" void func_003FEC50(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D9560;

struct func_004037A8_arg0 {
    char pad0[0xC];
    void *unkC;
};

extern "C" void func_004037A8(struct func_004037A8_arg0 *arg0, int arg1) {
    arg0->unkC = &D_005D9560;
    func_003FEC50(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
