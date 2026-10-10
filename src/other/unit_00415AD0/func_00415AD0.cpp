typedef int s32;
typedef float f32;

struct V2 { f32 x, y; };
struct Self { s32 m0, m4; f32 x, y; };
extern "C" void func_004158D0(Self *, V2 *, s32);

extern "C" void func_00415AD0(Self *self, s32 a) {
    V2 v;
    func_004158D0(self, &v, a);
    self->x = v.x;
    self->y = v.y;
}
