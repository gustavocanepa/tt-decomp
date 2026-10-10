typedef int s32;

struct Result { s32 pad[4]; s32 p; s32 pad14[3]; };
struct Obj { s32 f0; s32 f4; };
extern "C" void func_0047DB58(Result *, s32, s32, s32, s32);
extern "C" void func_00385B40(Obj *);

extern "C" void func_00385B68(Obj *o, s32 a, s32 b, s32 c) {
    if (o->f4 == 0) {
        Result r;
        o->f0 = b;
        func_0047DB58(&r, a, b, c, 1);
        o->f4 = r.p;
        func_00385B40(o);
    }
}
