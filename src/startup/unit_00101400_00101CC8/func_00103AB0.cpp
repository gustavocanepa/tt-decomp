typedef int s32;
typedef float f32;
typedef double d64;

struct Vec4 {
    f32 x, y, z, w;
};

struct Obj {
    char pad0[0x48];
    f32 w;
    Vec4 v;
};

extern "C" void func_00102300(Vec4 *v);

extern "C" void func_00103AB0(Obj *o) {
    Vec4 v = o->v;
    v.w = o->w;
    func_00102300(&v);
}
