typedef int s32;

struct Obj {
    char pad0[0x38];
    s32 unk38;
};

extern "C" s32 func_004FAFD8(s32 arg0);

extern "C" s32 func_004ECAE0(Obj *arg0) {
    return func_004FAFD8(arg0->unk38);
}
