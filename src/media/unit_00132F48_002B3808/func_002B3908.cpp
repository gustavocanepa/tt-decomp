/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *, s32, s32 *); };
struct VObj { char pad[4]; VEntry *vtbl; };
struct Items { char pad0[0x8]; s32 *list; char pad1[8]; s32 count; };
struct Outer { char pad[0x2c]; Items *items; };
struct Self { char pad[8]; s32 count; };
extern "C" void func_002B1548(void *, Outer **) throw();
extern "C" void func_002B1578(void *, s32) throw();
static inline void vcall(VObj *o, void *result, s32 n, s32 *args) {
    VEntry *e = &o->vtbl[23];
    e->fn((char *)o + e->delta, result, n, args);
}
static inline s32 *pop(Items *it, s32 n) {
    s32 idx = it->count - n;
    it->count = idx;
    return it->list + idx;
}
extern "C" void func_002B3908(Self *self, Outer *outer) {
    s32 result[4];
    Outer *ctx[4];
    s32 *p = pop(outer->items, self->count + 1);
    ctx[0] = outer;
    func_002B1548(result, ctx);
    vcall((VObj *)*p, result, self->count, p + 1);
    func_002B1578(result, 2);
}
