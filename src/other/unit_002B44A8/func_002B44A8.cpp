typedef int s32;
typedef float f32;

struct Obj {
    s32 a;
    void *vtbl;
    f32 f;
};

extern char D_005C6D00[];
extern "C" Obj *func_002C0EB0(Obj *);

extern "C" Obj *func_002B44A8(Obj *self, f32 f) {
    Obj *r = func_002C0EB0(self);
    self->vtbl = D_005C6D00;
    self->f = f;
    return r;
}
