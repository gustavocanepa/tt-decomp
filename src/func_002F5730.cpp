typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x754];
    f32 unk754;
};

extern "C" s32 func_002F5730(Obj *arg0) {
    return (s32)arg0->unk754;
}
