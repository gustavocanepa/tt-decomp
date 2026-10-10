typedef int s32;

struct Obj {
    char pad0[0x64];
    void *vtbl;
};

extern char D_005D5308[];

extern "C" void func_0037AB38(Obj *self, int flags);
extern "C" void func_00377348(void *self, int flags);
extern "C" void func_0050E1A8(void *p);

extern "C" void func_003882E8(Obj *self, int flags) {
    self->vtbl = D_005D5308;
    func_00377348((char *)self + 0x13C00, 2);
    func_0037AB38(self, 0);
    if (flags & 1) {
        return func_0050E1A8(self);
    }
}
