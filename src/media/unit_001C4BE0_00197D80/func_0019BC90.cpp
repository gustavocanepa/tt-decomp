/* compiler: ee-gcc2.96-stl */
struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
struct Loc { VT *vptr; int f4; };
struct EntI { short off; short pad; int (*fn)(void *); };
struct Arg { char *vptr; };
extern VT D_005AC7A0;
extern VT D_005A7A38;
static inline bool entry_true(EntI *e2, Arg *self) { return e2->fn((char *)self + e2->off) != 0; }
extern "C" int func_0019BC90(Arg *self, int arg1) {
    Loc l;
    l.vptr = &D_005AC7A0;
    VT *fin = &D_005A7A38;
    l.f4 = arg1;
    Ent *e = &l.vptr->e;
    e->fn((char *)&l + e->off, 0x1.e66666p-1f);
    EntI *e2 = (EntI *)(self->vptr + 0x48);
    if (entry_true(e2, self)) {
        l.vptr = fin;
        return 0;
    }
    Ent *e3 = &l.vptr->e;
    e3->fn((char *)&l + e3->off, 1.0f);
    l.vptr = fin;
    return 1;
}
