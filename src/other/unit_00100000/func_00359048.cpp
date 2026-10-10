typedef float f32;

struct Part { char b[0x20]; };
struct Obj { char pad[4]; Part a; Part b; };
extern "C" void func_0035E7B0(Part *, f32);
extern "C" void func_0035E938(Part *, f32);

extern "C" void func_00359048(Obj *o) {
    f32 dt = 1.0f / 60.0f;
    func_0035E7B0(&o->a, dt);
    func_0035E938(&o->b, dt);
}
