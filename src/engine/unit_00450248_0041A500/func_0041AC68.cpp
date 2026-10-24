/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Inner {
    char pad0[0x18];
    s32 f18;
    char pad1[4];
    s32 f20;
};

struct Obj {
    Inner *inner;
    char pad[0x34 - 4];
    s32 f34;
};

extern "C" s32 *func_0041AB10(Obj *) throw();
extern "C" s32 *func_0041AB50(Obj *) throw();
extern "C" void func_004200F8(s32, float, s32);
extern "C" void func_00422730(s32, s32 *, s32);

extern "C" void func_0041AC68(Obj *self, s32 arg, float t)
{
    Inner *in = self->inner;
    self->f34 = self->f34 + (s32)(t * 1000.0f);
    if (in != 0 && arg != 0) {
        s32 a = in->f18;
        s32 b = in->f20;
        if (a != 0) {
            s32 *p = func_0041AB10(self);
            func_00422730(*p, p, arg);
            func_004200F8(a, t, -1);
        }
        if (b != 0) {
            s32 *q = func_0041AB50(self);
            func_00422730(*q, q, arg);
        }
    }
}
