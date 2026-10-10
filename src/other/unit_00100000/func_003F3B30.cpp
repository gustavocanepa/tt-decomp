typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_003F4C58(s32 arg0, s32 arg1);

extern "C" s32 func_003F3B30(Obj *arg0, s32 arg1, s32 arg2) {
    return func_003F4C58(arg0->unk4 + (arg1 << 5), arg2);
}
