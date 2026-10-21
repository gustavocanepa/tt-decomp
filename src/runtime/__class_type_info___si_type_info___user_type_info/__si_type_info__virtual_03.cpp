typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32, s32, s32, s32); };
struct Inner { char pad[4]; char *vtbl; };
struct Obj { char pad[8]; struct Inner *base; };

extern "C" s32 func_0050C680(const char **a, const char **b);

extern "C" s32 __si_type_info__virtual_03(struct Obj *self, s32 a1, s32 a2, s32 a3, s32 a4)
{
    if (a4 == a3 && func_0050C680((const char **)a2, (const char **)self))
        return 6;
    struct Inner *o = self->base;
    struct VEntry *e = (struct VEntry *)(o->vtbl + 0x20);
    return e->fn((char *)o + e->delta, a1, a2, a3, a4);
}
