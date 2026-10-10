extern "C" void func_004887E0(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005DABB0;

struct func_00570DC0_arg0 {
    char pad0[0x78];
    void *unk78;
};

extern "C" void func_00570DC0(struct func_00570DC0_arg0 *arg0, int arg1) {
    arg0->unk78 = &D_005DABB0;
    func_004887E0(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
