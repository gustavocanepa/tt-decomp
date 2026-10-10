typedef int s32;
typedef float f32;

struct Vec3 {
    f32 x, y, z;
};

struct Obj {
    s32 unk0;
    s32 unk4;
    char pad8[0x100 - 8];
    s32 hit;
};

extern "C" s32 func_003226F8(s32 a, s32 b, s32 c, Vec3 *extent);

extern "C" void func_003187D0(Obj *self, s32 a, s32 b) {
    s32 h = self->unk4;
    Vec3 v;
    v.x = 0x1.999998p-5f;
    v.y = 0x1.999998p-5f;
    v.z = 0x1.999998p-5f;
    self->hit = func_003226F8(a, b, h, &v) != 0;
}
