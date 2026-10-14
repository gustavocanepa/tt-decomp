typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void *(*fn)(void *);
};

struct Obj {
    char pad[0];
    VEntry *vtbl;
};

extern "C" void *func_00400CF0(void *p);
extern "C" int func_005524A8(s32 a, void *p);

extern "C" int func_00400DB8(Obj *self, s32 arg) {
    VEntry *e = self->vtbl + 2;
    void *p = e->fn((char *)self + e->delta);
    return func_005524A8(arg, func_00400CF0(p));
}
