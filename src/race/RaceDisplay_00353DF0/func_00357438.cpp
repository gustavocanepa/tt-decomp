typedef int s32;
typedef short s16;

struct VEntry_003A1F38 {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a1);
};

struct Obj_003A1F38 {
    char *vt;
    char pad4[0x1C];
    s32 m20;
    char pad24[0xC];
    s32 m30;
};

extern "C" void func_00357390(Obj_003A1F38 *arg0, s32 arg1, s32 arg2);

extern "C" void func_00357438(Obj_003A1F38 *self, s32 arg1) {
    func_00357390(self, 4, arg1);
    VEntry_003A1F38 *e = (VEntry_003A1F38 *)(self->vt + 0x120);
    e->fn((char *)self + e->delta, self->m20);
    self->m30 = (self->m30 & 0xFFFF00FF) | 0x100;
}
