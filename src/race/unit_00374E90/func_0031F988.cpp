/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct V;
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32, s32, s32, s32, s32, float); };
struct V { char *vtbl; };
struct Q { char pad[0x80]; s32 u80; };
struct Slot { char pad[0x13C]; V *u13C; char pad2[0x19C - 0x140]; };
static inline void vcall(V *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, float f) {
    VEntry *e = (VEntry *)(o->vtbl + 0x138);
    e->fn((char *)o + e->delta, a1, a2, a3, a4, a5, f);
}
struct A {
    Q *p0;
    Slot *p4;
    V *p8;
    s32 pC;
    s32 p10;
    s32 p14;
    s32 *p18;
    s32 p1C;
};
struct Vec3i { s32 x, y, z; };
extern "C" bool func_003A8E88(Q *, s32, Vec3i *);
extern "C" float func_005357F8(s32);
extern "C" bool func_0031F988(struct A *self) {
    Vec3i v;
    bool r = func_003A8E88(self->p0, self->p14, &v);
    if (!r) return 0;
    {
        s32 z = v.z;
        s32 s0 = self->p0->u80;
        float f = func_005357F8(self->p1C);
        V *o = self->p8;
        VEntry *e = (VEntry *)(o->vtbl + 0x148);
        e->fn((char *)o + e->delta, self->p14, s0, v.y, z, 1, f);
        char *slot = (char *)self->p4;
        slot += self->p10 * 0x1B4;
        *(V **)(slot + 0x154) = self->p8;
        *self->p18 = 1;
        return 1;
    }

}
