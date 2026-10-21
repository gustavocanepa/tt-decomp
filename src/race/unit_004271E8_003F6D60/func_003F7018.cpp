typedef int s32;
struct VEntry { short delta; short index; s32 (*fn)(void *, void *); };
struct Obj { VEntry *vtbl; char pad[4]; char data[0x88]; };
extern "C" s32 func_003F7018(Obj *self, char *src) {
    __builtin_memcpy((char *)self + 8, src, 0x88);
    VEntry *e = self->vtbl + 4;
    return e->fn((char *)self + e->delta, src);
}
