/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
struct Loc { VT *vptr; void *f4; };
struct Loc2 { char *vptr; Loc *owner; float a; float b; };
struct VEntA { short off; short pad; s32 (*fn)(void *, void *); };
struct VEntB { short off; short pad; s32 (*fn)(void *); };
struct Result { int value; };
struct VEntC { short off; short pad; Result (*fn)(void *, void *, s32, Loc2 *); };
static inline int status(const Result *const x) { return x->value; }
struct Tgt { char *vtbl; };
struct Obj { char pad0[0x4C]; char *vtbl; };
extern VT D_005AC7A0;
extern VT D_005A7A38;
extern char D_005AD330[];
extern "C" bool func_0019C3F0(Obj *, Tgt *);
extern "C" s32 func_0019C4C8(Obj *, Tgt *, s32, s32);
extern "C" s32 func_0019C0D8(Obj *arg0, Tgt *arg1, s32 arg2, s32 arg3, void *arg4) {
    Loc l;
    l.vptr = &D_005AC7A0;
    VT *fin = &D_005A7A38;
    l.f4 = arg4;
    Ent *e = &l.vptr->e;
    e->fn((char *)&l + e->off, 0.0f);
    Ent *e2 = &l.vptr->e;
    e2->fn((char *)&l + e2->off, 0x1.999998p-4f);
    VEntA *v = (VEntA *)(arg0->vtbl + 0x38);
    if (v->fn((char *)arg0 + v->off, arg1) == 0) {
        l.vptr = fin; return 1;
    }
    Ent *e3 = &l.vptr->e;
    e3->fn((char *)&l + e3->off, 0x1.999998p-3f);
    if (!func_0019C3F0(arg0, arg1)) {
        VEntB *vb = (VEntB *)(arg1->vtbl + 0x28);
        if ((vb->fn((char *)arg1 + vb->off) ^ 2) != 0) {
            l.vptr = fin; return 1;
        }
    }
    Loc2 o;
    Loc2 *po = &o;
    po->vptr = D_005AD330;
    po->owner = &l;
    po->a = 0x1.999998p-3f;
    po->b = 0x1.666666p-1f;
    VT *fin2 = &D_005A7A38;
    VEntC *vc = (VEntC *)(arg0->vtbl + 0x18);
    Result result = vc->fn((char *)arg0 + vc->off, arg1, arg3, po);
    int r = status(&result);
    if (r) {
        int v = result.value;
        po->vptr = (char *)fin2; l.vptr = fin2; return v;
    }
    float one = 1.0f;
    Ent *e4 = &l.vptr->e;
    e4->fn((char *)&l + e4->off, one);
    if (func_0019C4C8(arg0, arg1, arg2, arg3) == 0) {
        po->vptr = (char *)fin2; l.vptr = fin2; return 1;
    }
    Ent *e5 = &l.vptr->e;
    e5->fn((char *)&l + e5->off, one);
    po->vptr = (char *)fin2; l.vptr = fin2; return 0;
}
