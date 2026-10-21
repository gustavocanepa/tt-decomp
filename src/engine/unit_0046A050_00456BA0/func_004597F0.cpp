typedef int s32;

extern "C" void *func_00459878(void *arg0);
extern "C" char D_005DA208[];

struct func_004597F0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x4];
    void *unk24;
};

extern "C" void *func_004597F0(struct func_004597F0_arg0 *arg0) {
    arg0->unk1C = 0;
    arg0->unk24 = D_005DA208;
    return func_00459878(arg0);
}
