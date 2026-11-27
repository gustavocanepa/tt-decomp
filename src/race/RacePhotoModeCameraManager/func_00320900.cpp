/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short index; void (*fn)(void *, int); };
struct Obj { VE *vt; };
struct Self { char *vt; char pad[0xD00 - 4]; Obj *a; Obj *b; };
extern char D_005C9850[];
extern "C" void func_00318440(void *, int);
extern "C" void func_0031AFF0(void *, void *) throw();
extern "C" void func_0050E1A8(int) throw();
static inline void destroy(Obj *o) {
    if (o != 0) {
        VE *e = o->vt + 1;
        e->fn((char *)o + e->delta, 3);
    }
}
extern "C" void func_00320900(Self *self, int flags) {
    self->vt = D_005C9850;
    destroy(self->a);
    destroy(self->b);
    func_00318440((char *)self + 0xF00, 2);
    func_0031AFF0(self, 0);
    if (flags & 1) return func_0050E1A8((int)self);
}
