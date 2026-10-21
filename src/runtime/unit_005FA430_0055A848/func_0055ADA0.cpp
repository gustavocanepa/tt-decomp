typedef int s32;
typedef float f32;

struct Obj { char pad[0xC8]; f32 unkC8; };

extern "C" s32 func_0055ADA0(Obj *arg0) {
    return (s32)arg0->unkC8;
}
