typedef int s32;

struct Obj {
    s32 a;
    s32 b;
    void *p;
    char pad[0x14];
    void *vtbl;
    char buf[4];
};

extern char D_005C90F0[];
extern "C" void func_0036BE28(Obj *);

extern "C" void func_002CE060(Obj *self) {
    func_0036BE28(self);
    self->vtbl = D_005C90F0;
    self->b = 6;
    self->p = self->buf;
}
