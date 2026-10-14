/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Node { Node *a; Node *b; Node *c; Node *d; };
struct Tree { char pad0[4]; Node *head; Node *size; u8 flag; Node *key; char padz[0x1c]; };
struct Obj { char pad0[4]; s32 f4; u16 f8; char padA[6]; s32 f10; char pad14[8]; s32 f1C; };
struct Ctx { char pad[0x164]; s32 f164; };
struct Vec { s32 a; void *p; s32 b; s32 c; s32 d; char padv[0xc]; };
extern "C" void func_004A45D0(void *) throw();
extern "C" void *func_004A4690(int, int);
extern "C" void func_00568DB0(void *, void *);
extern "C" void func_00440FC0(Obj *, Tree *, s32, s32) throw();
extern "C" void strobe__ActionInstance__doAction(s32, s32, s32, u16, void *, Tree *, Ctx *);
extern "C" void func_0044C0E8(Vec *, s32);

struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
extern char D_005A4C58[];
extern char D_006016F0[];
extern "C" char *strobe__toUpper(void *);
extern "C" int func_004A8368(const char *) throw();
extern "C" void *func_00550E18(void *, unsigned, unsigned, const char *, unsigned);
extern "C" void *func_00448190(void *, void *);
extern "C" void *func_0043D3E0(void *, void *) throw();

extern "C" s32 func_004412F0(s32 arg0, Obj *o, s32 arg2, void *arg3, s32 arg4, Obj *p, Ctx *c) {
    Node *key = (Node *)o->f10;
    Tree t;
    Str tmp;
    Vec v;
    void *volatile keep;
    volatile u8 fl = 0;
    volatile u8 *pf = &fl;
    t.head = 0;
    Node *n = (Node *)func_004A4690(0x10, 0x1C);
    t.head = n;
    t.size = 0;
    t.flag = *pf;
    n->a = 0;
    t.head->b = 0;
    t.head->c = t.head;
    t.head->d = t.head;
    *(Node *volatile *)&t.key = key;
    func_00440FC0(o, &t, *(volatile s32 *)&c->f164, arg4);
    const char *text = D_006016F0;
    Str *ps = &tmp;
    Rep *g = (Rep *)D_005A4C58;
    char *r;
    if (g->sel != 0) r = strobe__toUpper(g);
    else { r = (char *)g + 0x10; g->ref++; }
    ps->p = r;
    func_00550E18(ps, 0, (unsigned)-1, text, func_004A8368(text));
    func_0043D3E0(func_00448190(&t, ps), arg3);
    Rep *rep = (Rep *)(ps->p - 0x10);
    if (--rep->ref == 0) func_004A45D0(rep);
    s32 px = p->f10;
    s32 x = o->f1C;
    if (px == x) {
        strobe__ActionInstance__doAction(arg0, arg2, o->f4, o->f8, p, &t, c);
        if (t.size != 0) {
            func_00568DB0(&t, t.head->b);
            t.head->c = t.head;
            t.head->b = 0;
            t.head->d = t.head;
            t.size = 0;
        }
        func_004A45D0(t.head);
    } else {
        v.p = 0; v.b = 0; v.c = 0; v.d = 0;
        func_0044C0E8(&v, x);
        strobe__ActionInstance__doAction(arg0, arg2, o->f4, o->f8, &v, &t, c);
        void *q = v.p;
        keep = q;
        if (q) func_004A45D0(q);
        if (t.size != 0) {
            func_00568DB0(&t, t.head->b);
            t.head->c = t.head;
            t.head->b = 0;
            t.head->d = t.head;
            t.size = 0;
        }
        func_004A45D0(t.head);
    }
    return arg0;
}
