/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef long s64;
struct VEntry { s16 delta; s16 index; void *fn; };
struct Mat { s64 q[8]; };
struct In { s16 a, b, c, d, e, f; };
struct Dst { char pad[0xB00]; Mat m; };
struct Self { char pad0[0x64]; char *vt; char pad1[0xD8C - 0x68]; s32 f; };
extern "C" void func_00101C08(In *);
extern "C" void func_00101C28(Mat *, In *);
extern "C" void func_002CF350(Self *self) {
    VEntry *e = (VEntry *)(self->vt + 0xD0);
    Dst *d = ((Dst *(*)(void *, s32))e->fn)((char *)self + e->delta, 0);
    In in;
    Mat m;
    in.c = 0; in.b = 0; in.a = 0; in.f = 0; in.e = 0; in.d = 0;
    if (self->f == 0)
        func_00101C08(&in);
    Mat *p = &m;
    func_00101C28(p, &in);
    d->m = *p;
}
