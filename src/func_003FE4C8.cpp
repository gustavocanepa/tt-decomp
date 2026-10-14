/* compiler: ee-gcc2.96-no-strict-aliasing */
struct LEnt { int pad; int key; int pad2; const char *name; char pad3[8]; };
struct List { LEnt *data; unsigned count; int x; };
struct Ent { long long id; char t8; unsigned char t9; signed char a; signed char b; char pad[4]; };
struct Obj { int n; int pad0; short s8; char pad[6]; Ent e[128]; };
extern "C" void *func_0042D140(void *, int);
extern "C" short func_004B2AC8();
extern "C" long long func_00418938(int);
extern "C" void func_003FE6F0(Obj *, signed char);
extern "C" int func_004A8268(const char *, const char *) throw();

extern "C" void func_003FE4C8(Obj *o, Obj *src, const char *name, int s) {
    List l;
    func_0042D140(&l, 0xC);
    unsigned i;
    if (s == 0) {
        i = 0;
        o->s8 = func_004B2AC8();
    } else {
        o->s8 = s;
        i = 0;
    }
    for (i = 0; i < 128; i++) {
        o->e[i].t8 = 0;
        o->e[i].t9 = 0;
        o->e[i].id = 0;
    }
    o->n = 0;
    for (i = 0; i < l.count; i++) {
        if (src->e[i].t9) {
        LEnt *e = l.data + i;
        if (func_004A8268(e->name, name) == 0) {
            Ent *p = &o->e[o->n];
            p->id = func_00418938(((LEnt *)((char *)l.data + i * 0x18))->key);
            p->a = (unsigned char)o->n;
            p->b = (unsigned char)o->n;
            p->t9 = 1;
            o->n++;
        }
        }
    }
    if (o->n == 0) {
        o->n = 0;
        for (i = 0; i < l.count; i++) {
            LEnt *e = l.data + i;
            Ent *p = &o->e[o->n];
            if (func_004A8268(e->name, name) == 0) {
                p->id = func_00418938(((LEnt *)((char *)l.data + i * 0x18))->key);
                p->a = (unsigned char)o->n;
                p->b = (unsigned char)o->n;
                o->n++;
            }
        }
        func_003FE6F0(o, 0);
    }
}
