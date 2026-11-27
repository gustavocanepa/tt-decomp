/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pt { float x, y; };
struct Node {
    char pad0[0xCC];
    Pt *a;
    char pad1[8];
    Pt *b;
    char pad2[4];
    int fE0;
    int fE4;
    Node *next;
};
struct It {
    void *owner;
    Node *n;
    It(Node *p) : n(p) {}
    It(const It &o) : n(o.n) {}
};
struct PP { Pt *first; Pt *second; };
struct Owner { char pad[0x4E0C]; Node *head; };

extern "C" void func_0056B050(Owner *self, Pt *a, Pt *b);

extern "C" int func_0056AE88(Owner *self) {
    It end(self->head);
    It cur(end.n->next);
    while (cur.n != end.n) {
        PP pp;
        if (cur.n->fE0 == 0) {
            cur.n->fE0 = 1;
            pp.first = cur.n->a;
            pp.second = cur.n->b;
            if (pp.first->y < pp.second->y ||
                (pp.first->y == pp.second->y && pp.first->x < pp.second->x)) return 1;
        } else if (cur.n->fE4 == 0) {
            cur.n->fE4 = 1;
            pp.second = cur.n->a;
            pp.first = cur.n->b;
            if (pp.first->y < pp.second->y ||
                (pp.first->y == pp.second->y && pp.first->x < pp.second->x)) return 1;
        } else {
            cur.n = cur.n->next;
            continue;
        }
        func_0056B050(self, pp.second, pp.first);
        return 1;
    }
    return 0;
}
