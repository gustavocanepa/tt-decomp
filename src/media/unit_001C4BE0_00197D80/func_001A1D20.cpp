/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void *fn; };
struct Obj { VEntry *vt; };
struct Info { char pad[0x10]; int value; char tail[0x2C]; };
extern "C" int func_001A1D20(Obj *self, int key) {
    Info info;
    VEntry *e = self->vt + 13;
    int miss = ((int (*)(void *, int, Info *, int, int))e->fn)((char *)self + e->delta, key, &info, 0, 1);
    VEntry *f = self->vt + 5;
    if (((int (*)(void *))f->fn)((char *)self + f->delta) != 0) return -1;
    miss ^= 1;
    return miss == 0 ? info.value : -2;
}
