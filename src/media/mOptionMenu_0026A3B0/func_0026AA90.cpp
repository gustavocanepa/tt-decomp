typedef int s32;

struct Obj {
    char pad[0xF4];
    s32 unkF4;
};

extern "C" s32 func_0026AA18(Obj *arg0, s32 arg1);

extern "C" s32 func_0026AA90(Obj *arg0) {
    return func_0026AA18(arg0, arg0->unkF4);
}
