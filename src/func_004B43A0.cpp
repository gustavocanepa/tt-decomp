typedef int s32;

struct Obj {
    char pad[0xC];
    s32 unkC;
};

extern "C" s32 func_004B42E8(Obj *arg0, s32 arg1);

extern "C" s32 func_004B43A0(Obj *arg0) {
    return func_004B42E8(arg0, arg0->unkC) + 2;
}
