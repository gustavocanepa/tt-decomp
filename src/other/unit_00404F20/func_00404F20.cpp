typedef int s32;

struct Obj {
    char pad0[0xC];
    void *vtbl;
};

extern char D_00585930[];
extern char D_005D9720[];

extern "C" void *func_003FEC30(Obj *self, void *def);

extern "C" void *func_00404F20(Obj *self, void *def) {
    if (def == 0) {
        def = D_00585930;
    }
    void *r = func_003FEC30(self, def);
    self->vtbl = D_005D9720;
    return r;
}
