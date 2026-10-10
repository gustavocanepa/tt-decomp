typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0x4];
    u32 unk4;
};

extern "C" s32 func_00340B30(Obj *arg0, s32 arg1);

extern "C" s32 func_00340B90(Obj *arg0) {
    return func_00340B30(arg0, arg0->unk4 < 1);
}
