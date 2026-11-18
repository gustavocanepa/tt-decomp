/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };
struct Items { char pad0[0x8]; s32 *list; char pad1[8]; s32 count; };
struct Rhs { char pad0[0x30]; s32 *tab; };
struct Self { char pad0[0x24]; Rhs *rhs; s32 *out; Items *items; };

static inline s32 vcall(void *o) {
    VObj *ob = (VObj *)o;
    VEntry *e = &ob->vtbl[13];
    return e->fn((char *)o + e->delta);
}

extern "C" void func_002B55C8(s32 *arg0, void *arg1) {
    Self *self = (Self *)arg1;
    Items *it = self->items;
    s32 idx = it->count - 1;
    it->count = idx;
    s32 *ep = it->list + idx;
    VObj *o = (VObj *)*ep;
    if (vcall(o) == 0) {
        Rhs *rh = self->rhs;
        s32 k = arg0[2];
        s32 *v;
        if (rh != 0) {
            v = rh->tab + k;
        } else {
            v = 0;
        }
        self->out = v;
    }
}
