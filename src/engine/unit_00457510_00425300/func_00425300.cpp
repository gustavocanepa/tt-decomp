typedef float f32;

struct Obj {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

extern "C" Obj *func_00425300(Obj *arg0) {
    f32 zero = 0.0f;
    f32 one = 1.0f;
    arg0->unk0 = zero;
    arg0->unk4 = one;
    arg0->unk8 = zero;
    return arg0;
}
