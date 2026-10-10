typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x34];
    f32 unk34;
};

extern "C" s32 func_00318950(f32 arg0);

extern "C" s32 func_00318AB8(Obj *arg0) {
    return func_00318950(arg0->unk34);
}
