typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad[0x4];
    char *vtbl;
};

extern "C" void func_001E49E8(s32 arg0, Obj *arg1);
extern "C" void func_001E4C78(s32 arg0, Obj *arg1);

extern "C" void func_0020B640(Obj *self, s32 arg1) {
    func_001E49E8(arg1, self);
    VEntry *e = (VEntry *)(self->vtbl + 0x368);
    e->fn((char *)self + e->delta, arg1);
    func_001E4C78(arg1, self);
}
