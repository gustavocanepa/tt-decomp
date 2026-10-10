typedef float f32;

struct Obj {
    char pad[0x30];
    f32 unk30;
};

extern "C" f32 func_003189A0(Obj *arg0, f32 arg1);

extern "C" f32 func_00318AA0(Obj *arg0) {
    return func_003189A0(arg0, arg0->unk30);
}
