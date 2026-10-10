typedef int s32;

struct Obj {
    char pad[0x14];
    s32 unk14;
};

extern "C" s32 func_00408B58(s32 arg0);
extern "C" s32 func_0040D5A8(s32 arg0, s32 arg1);

extern "C" s32 func_00131A08(Obj *arg0, s32 arg1) {
    s32 s0 = arg1;
    s32 v0 = func_00408B58(arg0->unk14);
    return func_0040D5A8(v0, s0);
}
