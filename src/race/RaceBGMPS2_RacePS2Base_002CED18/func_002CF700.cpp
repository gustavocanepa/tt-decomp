struct Ent { short delta; short pad; void (*fn)(void *); };
struct Sub { int unk0; int unk4; char *vt; };
struct Elem { char pad0[0x18]; int unk18; char pad1[0x4840 - 0x1C]; Sub *sub; };
struct B { int count; char pad[4]; Elem **arr; };
struct C { char pad[4]; int unk4; };
struct A { char pad0[0x60]; B *b; char pad1[0x80 - 0x64]; C *c; };
struct Outer { char pad0[0x6C]; A *a; };

extern "C" void CourseData__DMAsafe(int arg0);
extern "C" int func_00369AE8(void *arg0);

extern "C" void func_002CF700(Outer *arg0) {
    A *a = arg0->a;
    int n = a->b->count;
    int i;
    CourseData__DMAsafe(a->c->unk4);
    for (i = 0; i < n; i++) {
        Elem *e = a->b->arr[i];
        Sub *x = e->sub;
        Ent *ent = (Ent *)(x->vt + 0x30);
        ent->fn((char *)x + ent->delta);
    }
    if (n == 2) {
        Elem *e = a->b->arr[1];
        if (func_00369AE8(e) != 0) {
            e->sub->unk4 = e->unk18;
        }
    }
}
