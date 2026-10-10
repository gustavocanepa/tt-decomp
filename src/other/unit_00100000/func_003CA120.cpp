typedef int s32;

struct S {
    void *unk0;
    s32 unk4;
};

extern "C" void func_00422818(S *arg0, s32 arg1);

extern S D_00769510;
extern char D_005D70B0;

extern "C" void func_003CA120(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            D_00769510.unk4 = 0;
            D_00769510.unk0 = &D_005D70B0;
        }
        if (arg0 == 0) {
            D_00769510.unk0 = &D_005D70B0;
            func_00422818(&D_00769510, 0);
        }
    }
}
