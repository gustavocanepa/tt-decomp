/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj;
struct VEnt { short off; short pad; void *fn; };
typedef int (*Fn3)(void *, int, int);
typedef void (*Fn2)(void *, int);
struct Obj { char pad[0x50]; unsigned key; char pad2[8]; VEnt *vt; };
struct F { unsigned char c; int pad[3]; };
struct SP { Obj *obj; SP *a; SP *b; };
struct Node { Node *next; Node *prev; SP sp; };
struct Lst { int pad; Node *head; };
struct Key { char pad[8]; unsigned short id; };
struct Owner { int tab; char pad[0x60]; int v64; char pad2[0x3C]; Lst lst; };
struct It { Node *n; int pad[3]; };
extern "C" void func_0056B7F8(It *, It *, It *, unsigned short *, unsigned char, int);
extern "C" Obj *func_00444228(int, Key *, int, int, Owner *);
extern "C" void *func_004A4690(int, int);
extern "C" Node **func_00446F20(Node **out, Owner *self, Key *key, int arg3) {
    It res;
    It first;
    It last;
    F flag;
    It c1;
    It c2;
    It *pl = &last;
    It *pc2 = &c2;
    It *pf = &first;
    It *pc = &c1;
    Lst *l = &self->lst;
    pf->n = l->head->next;
    pl->n = l->head;
    flag.c = 0;
    pc->n = pf->n;
    pc2->n = pl->n;
    func_0056B7F8(&res, pc, &c2, &key->id, flag.c, 0);
    Node *end = l->head;
    pc->n = end;
    int found;
    found = 0;
    if (res.n != end) found = (res.n->sp.obj->key == key->id);
    if (found) {
        *out = end;
    } else {
        SP sp;
        SP *ps = &sp;
        ps->obj = func_00444228(self->tab, key, arg3, self->v64, self);
        ps->a = ps;
        ps->b = ps;
        VEnt *e = &ps->obj->vt[6];
        ((Fn3)e->fn)((char *)ps->obj + e->off, arg3, 1);
        pf->n = res.n;
        Node *nn = (Node *)func_004A4690(0x10, 0x14);
        SP *p = &nn->sp;
        if (p) {
            Obj *o = ps->obj;
            p->a = ps;
            p->obj = o;
            p->b = ps->b;
            ps->b = p;
        }
        nn->next = first.n;
        nn->prev = first.n->prev;
        first.n->prev->next = nn;
        first.n->prev = nn;
        pc->n = nn;
        *out = res.n;
        if (ps->a == ps->b) {
            if (ps->obj) {
                VEnt *e2 = &ps->obj->vt[1];
                ((Fn2)e2->fn)((char *)ps->obj + e2->off, 3);
            }
        } else {
            ps->b->a = ps->a;
            ps->a->b = ps->b;
        }
    }
    return out;
}
