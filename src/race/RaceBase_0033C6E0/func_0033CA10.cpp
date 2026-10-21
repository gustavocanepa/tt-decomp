/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *, int *); };
struct Obj { char pad[0x64]; VEntry *vtbl; };
extern "C" int func_0033CA70(int);
extern "C" int func_0033CA10(Obj *self, int *mode) {
    *mode = -1;
    VEntry *e = (VEntry *)((char *)self->vtbl + 0x308);
    return func_0033CA70(e->fn((char *)self + e->delta, mode));
}
