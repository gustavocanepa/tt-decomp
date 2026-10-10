typedef int s32;
typedef float f32;

struct Vec3_0044DD98 {
    f32 x, y, z;
};

struct Obj_0044DD98 {
    char pad0[8];
    f32 m8;
    f32 mC;
};

extern "C" void func_004158D0(Obj_0044DD98 *o, Vec3_0044DD98 *out, Vec3_0044DD98 *in);

extern "C" void GT3OLDFONT__GT3OldFontManagerClass__position(Obj_0044DD98 *o, s32 x, s32 y, s32 z) {
    Vec3_0044DD98 v;
    v.x = x;
    v.y = y;
    v.z = z;
    func_004158D0(o, &v, &v);
    o->m8 = v.x;
    o->mC = v.y;
}
