/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Buf { unsigned short flags, refs; int value; };
struct Node { Node *next, *prev; Buf *data; };
extern "C" void func_004A45D0(void *) throw();
extern "C" void func_00488070(void *);
extern "C" int func_0056F300(void *, const int *);
struct It {
    Node *n;
    char pad[12];
    It(Node *p): n(p) {}
    It(const It &o): n(o.n) {}
};
struct Temp { int value; char pad[12]; };
struct List {
    int a,b;
    Node *node;
    char rest[16];
    It begin() { return node->next; }
    It erase(It pos) {
        Node *next = pos.n->next;
        Node *prev = pos.n->prev;
        prev->next = next;
        next->prev = prev;
        func_004A45D0(pos.n);
        return next;
    }
};
extern "C" Buf *func_004876F0(List *self, int value) {
    Buf *data = self->begin().n->data;
    self->erase(self->begin());
    if ((unsigned short)(data->flags & 1)) func_00488070(self);
    int t = data->value;
    func_0056F300((char *)self + 12, &t);
    data->value = value;
    data->refs = 1;
    data->flags = 0;
    return data;
}
