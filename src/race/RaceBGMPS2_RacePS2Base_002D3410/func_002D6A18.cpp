/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void *fn; };
struct Obj { VEntry *vt; };
struct Self { char pad[0x64]; VEntry *vt; char gap[0xD8C-0x68]; int enabled; };
typedef Obj *(*Get)(void *, int);
typedef int (*Flags)(void *);
extern "C" int func_002D6A18(Self *self) {
    int result = 0;
    if (self->enabled) {
        VEntry *e = (VEntry *)((char *)self->vt + 0xD0);
        Obj *o = ((Get)e->fn)((char *)self + e->delta, 0);
        VEntry *f = (VEntry *)((char *)o->vt + 0x118);
        if (((Flags)f->fn)((char *)o + f->delta) & 0x4000) result = 1;
    }
    return result;
}
