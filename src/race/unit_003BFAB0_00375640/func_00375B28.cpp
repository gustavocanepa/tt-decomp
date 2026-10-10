typedef int s32;

struct Obj {
    char pad0[0x80];
    s32 unk80;
};

extern "C" s32 func_0034AFD0(s32 arg0, s32 arg1);

extern "C" s32 func_00375B28(Obj *arg0) {
    return func_0034AFD0(arg0->unk80, 1);
}
