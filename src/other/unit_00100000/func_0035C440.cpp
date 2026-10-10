typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Part { char b[0x20]; };
struct Obj { char pad[0x18]; u8 f18; char pad19[3]; Part p; };
extern "C" void func_0035E7B0(Part *, f32);
extern "C" void func_0035E8F0(Part *, s32, s32);

extern "C" void func_0035C440(Obj *o, f32 dt) {
    func_0035E7B0(&o->p, dt);
    func_0035E8F0(&o->p, o->f18 ? -1 : 0, 0);
}
