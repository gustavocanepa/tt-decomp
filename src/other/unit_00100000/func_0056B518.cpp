/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    char pad0[0xE8];
    Node *prev;
    Node *next;
};

struct Iter {
    int f0;
    Node *node;
};

struct List {
    char pad0[0x1E08];
    int count;
};

extern "C" Node *func_0056B600(List *l, Node *prev, Node *next);

extern "C" void func_0056B518(List *l, Iter *pos) {
    Node *p = pos->node;
    Node *n = func_0056B600(l, p, p->next);
    l->count++;
    p->next = n;
    n->next->prev = n;
}
