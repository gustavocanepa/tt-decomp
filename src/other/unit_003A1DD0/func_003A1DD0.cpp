typedef int s32;

struct S00347188 {
    char pad0[0x1C];
    s32 unk1C;
};

extern "C" s32 func_002F8AE8(s32 arg0, s32 arg1);

extern "C" s32 func_003A1DD0(struct S00347188 **arg0, s32 arg1) {
    return func_002F8AE8(arg1, (*arg0)->unk1C);
}
