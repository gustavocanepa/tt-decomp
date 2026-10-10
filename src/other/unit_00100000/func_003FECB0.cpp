typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, s32); };
struct Self { s32 m0; char pad[8]; VEntry *vtbl; };
extern "C" s32 func_003FEB98(s32);

extern "C" s32 func_003FECB0(Self *self) {
    s32 v = func_003FEB98(self->m0);
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x28);
    return e->fn((char *)self + e->delta, v);
}
