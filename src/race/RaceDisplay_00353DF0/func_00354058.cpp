/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEnt { s16 delta; s16 idx; void *fn; };
struct Dev { char pad[0x64]; char *vtbl; };
struct Ctx { char pad0[0x84]; Dev *p84; char pad88[0xF0 - 0x88]; s32 pF0; };
struct Self {
    char *vtbl;
    Ctx *ctx;
    char pad8[0x14];
    s32 i1C;
    s32 i20;
    char pad24[8];
    signed char c2C;
    char pad2d[2];
    signed char id2F;
};
struct Obj { char *vtbl; };

extern void **D_00584418;
extern "C" void func_0031AAB8(void *, s32);
extern "C" s32 func_0031C798(void *, s32);
extern "C" void RaceMessageDisplay__clear(void *);

extern "C" void func_00354058(Self *self) {
    Dev *a2 = self->ctx->p84;
    if (a2) {
        signed char s2 = 0;
        VEnt *e = (VEnt *)(a2->vtbl + 0xD0);
        Obj *s1 = ((Obj *(*)(void *, s32))e->fn)((char *)a2 + e->delta, 0);
        s32 v = self->i1C;
        if (v < 10) {
            if (v >= 8) s2 = self->id2F;
        }
        func_0031AAB8(s1, s2);
        s32 r = func_0031C798(s1, s2);
        signed char s2_2 = 0;
        if (r != 0) {
            s2_2 = 2;
        } else {
            VEnt *e2 = (VEnt *)(s1->vtbl + 0x1C8);
            if (((s32 (*)(void *))e2->fn)((char *)s1 + e2->delta) != 0 && (self->i20 ^ 4) != 0) {
                s2_2 = self->ctx->pF0 == 0;
            }
        }
        s32 cur = self->c2C;
        if (cur != s2_2) {
            self->c2C = s2_2;
            if (cur >= 0) {
                s32 idx;
                switch (self->c2C) {
                case 1: idx = 0x1E; break;
                case 2: idx = 0x1B; break;
                case 0:
                default: idx = 0x1D; break;
                }
                VEnt *e3 = (VEnt *)(self->vtbl + 0xA8);
                ((void (*)(void *, void *, s32, s32))e3->fn)((char *)self + e3->delta, D_00584418[idx], 0, 0);
                RaceMessageDisplay__clear((char *)self + 0x239C);
                RaceMessageDisplay__clear((char *)self + 0x2A2C);
            }
        }
    }
}
