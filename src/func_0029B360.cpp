typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x10];
    f32 unk10;
};

extern "C" s32 func_0029B360(Obj *arg0) {
    return (s32)arg0->unk10;
}
