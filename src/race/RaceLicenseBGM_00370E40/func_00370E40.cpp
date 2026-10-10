extern "C" void *RaceBGMPS2__structor_0(void *arg0);
extern "C" char D_005D2C98[];

struct func_00370E40_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x11E0];
    int unk11E8;
};

extern "C" void func_00370E40(struct func_00370E40_arg0 *arg0)
{
    RaceBGMPS2__structor_0(arg0);
    arg0->unk4 = D_005D2C98;
    arg0->unk11E8 = 0;
}
