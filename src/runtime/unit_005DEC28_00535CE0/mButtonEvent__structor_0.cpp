typedef int s32;

extern void *D_005B56A0;
extern "C" void *func_00211C00(void *);

struct mButtonEvent__structor_0_arg0 {
    char pad0[0x4];
    void *unk4;
    char pad8[0x18];
    short unk20;
    char pad22[0x2];
    void *unk24;
    float unk28;
    float unk2C;
};

extern "C" void *mButtonEvent__structor_0(struct mButtonEvent__structor_0_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, float farg0, float farg1) {
    void *r0 = func_00211C00(arg0);
    arg0->unk2C = farg1;
    arg0->unk20 = arg3;
    arg0->unk24 = (void *)(arg4);
    arg0->unk28 = farg0;
    arg0->unk4 = &D_005B56A0;
    return r0;
}
