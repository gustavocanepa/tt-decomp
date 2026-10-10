typedef short s16;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    int (*fn)(void *self);
};

struct Obj {
    char pad0[0x241CC];
    VEntry *vtbl;
};

extern f32 D_00584CD8[];

extern "C" f32 DynamicsConductorMachineTest__GetGoalV(Obj *self) {
    f32 *table = D_00584CD8;
    VEntry *e = &self->vtbl[43];
    int i = e->fn((char *)self + e->delta);
    return table[i - 1];
}
