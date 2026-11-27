/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pt { float x, y; };
struct Node {
    char pad0[0x8C];
    Pt *a;
    char pad1[8];
    Pt *b;
    char pad2[4];
    int fA0;
    int fA4;
    Node *next;
};
struct It {
    void *owner;
    Node *n;
    It(Node *p) : n(p) {}
    It(const It &o) : n(o.n) {}
};
struct PP { Pt *first; Pt *second; };
struct Owner { char pad[0x358C]; Node *head; };

extern "C" void func_0055BEC0(Owner *self, Pt *a, Pt *b);

static inline bool less(Pt *a, Pt *b) {
    if (a->y < b->y) return true;
    if (a->y == b->y) return a->x < b->x;
    return false;
}

extern "C" int func_0055BC20(Owner *self) {
    It end(self->head);
    It cur(end.n->next);
    PP pp;
    while (cur.n != end.n) {
        if (cur.n->fA0 == 0) {
            cur.n->fA0 = 1;
            pp.first = cur.n->a;
            pp.second = cur.n->b;
            if (pp.first->y < pp.second->y ||
                (pp.first->y == pp.second->y && pp.first->x < pp.second->x)) return 1;
        } else if (cur.n->fA4 == 0) {
            cur.n->fA4 = 1;
            pp.second = cur.n->a;
            pp.first = cur.n->b;
            if (pp.first->y < pp.second->y ||
                (pp.first->y == pp.second->y && pp.first->x < pp.second->x)) return 1;
        } else {
            cur.n = cur.n->next;
            continue;
        }
        func_0055BEC0(self, pp.second, pp.first);
        return 1;
    }
    return 0;
}
