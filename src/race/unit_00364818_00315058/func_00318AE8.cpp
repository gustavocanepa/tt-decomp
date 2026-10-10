typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x60];
    f32 unk60;
};

extern "C" s32 func_00318950(f32 arg0);

extern "C" s32 func_00318AE8(Obj *arg0) {
    return func_00318950(arg0->unk60);
}
