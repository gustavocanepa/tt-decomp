typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, s32);
};

struct VObj {
    char pad[0x64];
    VEntry *vtbl;
};

struct Self {
    char pad[0x84];
    VObj *m84;
};

extern "C" s32 func_00376B98(Self *self, s32 a1, s32 a2) {
    VObj *o = self->m84;
    if (o != 0) {
        VEntry *e = (VEntry *)((char *)o->vtbl + 0x2B0);
        return e->fn((char *)o + e->delta, a1, a2);
    }
    return 0;
}
