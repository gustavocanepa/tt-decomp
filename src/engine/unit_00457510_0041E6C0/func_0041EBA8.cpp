typedef float f32;

struct Vec3 { f32 x, y, z; char pad[4]; };
struct VEntry { short delta; short index; void (*fn)(Vec3 *, void *); };
struct Obj { VEntry *vtbl; };
extern "C" void func_00475758(f32);
extern "C" void func_00475730(f32);
extern "C" void func_00475780(f32);

extern "C" void func_0041EBA8(Obj *o) {
    Vec3 v;
    VEntry *e = o->vtbl + 7;
    e->fn(&v, (char *)o + e->delta);
    func_00475758(v.y);
    func_00475730(v.x);
    func_00475780(v.z);
}
