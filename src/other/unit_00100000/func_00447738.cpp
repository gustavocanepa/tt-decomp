typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad[0x5C];
    char *vtbl;
};

extern "C" Obj *func_004475D8(void *, s32);

extern "C" s32 func_00447738(void *self, s32 id, s32 value) {
    Obj *o = func_004475D8(self, id);
    if (o == 0)
        return 0;
    VEntry *e = (VEntry *)(o->vtbl + 0x48);
    e->fn((char *)o + e->delta, value);
    return 1;
}
