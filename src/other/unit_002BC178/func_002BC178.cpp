typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
};

extern s32 D_0057C5D0;

extern "C" s32 func_002BC178(Obj *arg0) {
    return arg0->unk8 != D_0057C5D0;
}
