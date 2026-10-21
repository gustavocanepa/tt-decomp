typedef int s32;

struct Obj {
    char pad[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

extern "C" s32 func_004130B8(struct Obj *arg0, s32 arg1) {
    if (arg1 >= arg0->unk4 || arg1 < 0) {
        return 0;
    }
    return arg0->unkC + arg0->unk8 * arg1;
}
