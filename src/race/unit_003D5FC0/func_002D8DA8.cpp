typedef int s32;

struct Obj {
    char pad[0x4C];
    s32 unk4C;
};

extern "C" s32 func_002D8D20(struct Obj *arg0, s32 arg1);

extern "C" s32 func_002D8DA8(struct Obj *arg0) {
    s32 v = arg0->unk4C - 1;
    if (v < 0) v = 0;
    return func_002D8D20(arg0, v);
}
