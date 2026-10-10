typedef int s32;

struct Obj {
    char pad0[0xC8];
    s32 unkC8;
};

extern "C" s32 func_004C9B10(s32 arg0);

extern "C" s32 func_00574EB0(Obj *arg0) {
    return func_004C9B10(arg0->unkC8);
}
