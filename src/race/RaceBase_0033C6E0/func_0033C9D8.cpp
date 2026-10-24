/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" int func_0033C9D8(Obj *self, int *mode) {
    *mode = -1;
    VEntry *e = &self->vtbl[97];
    return e->fn((char *)self + e->delta, mode);
}
