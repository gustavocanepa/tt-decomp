typedef int s32;

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" s32 func_0040F2D8(s32 arg0);

extern "C" s32 func_0055AE38(Obj *arg0) {
    return func_0040F2D8(arg0->unk70);
}
