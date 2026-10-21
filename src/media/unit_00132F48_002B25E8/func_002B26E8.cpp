/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32 *); };
struct VObj { char pad[4]; VEntry *vtbl; };
struct Items { char pad0[0x8]; s32 *list; char pad1[8]; s32 count; };
struct Self { char pad[0x2c]; Items *items; };
extern "C" void func_002C0FE8(s32 p);
extern "C" void func_002C1050(s32 p);
static inline void vcall(VObj *o, s32 *value) {
    VEntry *e = (VEntry *)((char *)o->vtbl + 0xA8);
    e->fn((char *)o + e->delta, value);
}
extern "C" void func_002B26E8(void *arg0, Self *self) {
    Items *it = self->items;
    s32 idx = it->count - 1;
    it->count = idx;
    s32 *src = it->list + idx;
    Items *it2 = self->items;
    s32 idx2 = it2->count - 1;
    it2->count = idx2;
    s32 *p = it2->list + idx2;
    vcall((VObj *)*p, src);
    Items *out = self->items;
    s32 *dst = out->list + out->count;
    if (dst != src) {
        s32 newVal = *src;
        if (newVal != 0) func_002C0FE8(newVal);
        s32 oldVal = *dst;
        if (oldVal != 0) func_002C1050(oldVal);
        *dst = newVal;
    }
    out->count = out->count + 1;
}
