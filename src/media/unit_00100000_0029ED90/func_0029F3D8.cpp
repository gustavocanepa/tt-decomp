struct VEntry { short delta; short index; int (*fn)(void *); };
struct ReadEntry { short delta; short index; bool (*fn)(void *, void *, int); };
struct Obj { int field0; VEntry *vtbl; };
extern "C" int func_0029F3D8(Obj *self) {
    unsigned char c;
    VEntry *e = &self->vtbl[56];
    if (e->fn((char *)self + e->delta) != 0) return -1;
    ReadEntry *r = (ReadEntry *)((char *)self->vtbl + 0x1B0);
    c = 0;
    bool success = r->fn((char *)self + r->delta, &c, 1);
    if (success == false) return -1;
    return c;
}
