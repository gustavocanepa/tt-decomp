typedef int s32;
typedef float f32;
struct Blk { f32 f0; f32 f4; s32 f8; f32 fC; f32 f10; s32 f14; f32 f18; f32 f1C; s32 f20; };
extern "C" void func_0046D810(s32, void *, s32, s32, s32, s32);
extern "C" Blk *func_00473980(s32);

extern "C" void func_00119710(f32 a, f32 b, f32 c, f32 d) {
    Blk *v = func_00473980(3);
    v->f4 = c;
    f32 sum = a + b;
    f32 diff = a - b;
    v->f10 = c;
    v->f18 = a;
    v->f1C = d;
    v->f0 = sum;
    v->fC = diff;
    v->f8 = 0;
    v->f14 = 0;
    v->f20 = 0;
    func_0046D810(3, v, 0, 0, 0, 0);
}
