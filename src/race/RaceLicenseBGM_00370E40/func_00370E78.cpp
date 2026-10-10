extern "C" void RaceBGMPS2__structor_1(void *arg0, void *arg1);
extern "C" void func_0050E1A8(void *arg0);

extern void *D_005D2C98;

struct func_00370E78_arg0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void func_00370E78(struct func_00370E78_arg0 *arg0, int arg1) {
    arg0->unk4 = &D_005D2C98;
    RaceBGMPS2__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
