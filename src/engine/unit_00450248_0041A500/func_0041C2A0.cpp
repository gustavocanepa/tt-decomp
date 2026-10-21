typedef int s32;
typedef float f32;

struct Args {
    f32 a;
    f32 b;
    f32 c;
    s32 d;
};

extern "C" void func_00475850(void *self, Args *args);
extern "C" char D_00769CE0[];

extern "C" void func_0041C2A0(f32 x, f32 y, f32 z) {
    Args args;
    args.a = x;
    args.b = y;
    args.c = z;
    args.d = 0;
    func_00475850(D_00769CE0, &args);
}
