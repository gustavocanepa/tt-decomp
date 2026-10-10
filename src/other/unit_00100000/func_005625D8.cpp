typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x70];
    s32 unk70;
};

extern "C" void func_005625D8(struct Obj *arg0, f32 arg1) {
    arg0->unk70 = (s32)(arg1 * 128.0f);
}
