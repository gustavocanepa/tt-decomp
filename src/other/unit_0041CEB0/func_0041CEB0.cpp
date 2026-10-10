typedef int s32;
typedef float f32;

struct Obj {
    s32 unk0;
    f32 t;
};

extern "C" void func_00421C80(f32 frac);

extern "C" s32 func_0041CEB0(Obj *self) {
    f32 f = self->t * 6.0f;
    s32 i = (s32)f;
    func_00421C80(f - (f32)i);
    return i;
}
