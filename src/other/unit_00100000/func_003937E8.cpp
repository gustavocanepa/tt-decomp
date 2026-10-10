struct VEntry {
    short delta;
    short index;
    void (*fn)(void *);
};

struct Node {
    Node *next;
    VEntry *vtbl;
};

struct List {
    int f0;
    Node *head;
};

extern "C" void func_003937E8(List *l) {
    for (Node *n = l->head; n; n = n->next) {
        VEntry *e = &n->vtbl[4];
        e->fn((char *)n + e->delta);
    }
}
