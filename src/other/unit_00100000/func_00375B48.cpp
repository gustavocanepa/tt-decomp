typedef int s32;

struct Obj003C0098 {
    char pad0[0x80];
    s32 unk80;
};

extern "C" s32 func_0034B048(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00375B48(struct Obj003C0098 *arg0, s32 arg1) {
    return func_0034B048(arg0->unk80, arg1, 1);
}
