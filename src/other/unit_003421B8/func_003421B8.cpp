typedef int s32;
typedef float f32;

struct Obj;

extern "C" s32 func_00341AD8(Obj *arg0);

struct Ret {
    char pad[0x14];
    f32 unk14;
};

extern "C" f32 func_003421B8(Obj *arg0) {
    return ((Ret *)func_00341AD8(arg0))->unk14;
}
