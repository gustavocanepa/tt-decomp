/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next; Node *prev; int value; };
struct Obj { char pad[0x1c]; Node *head; int state; };
struct It {
    Node *node;
    It(Node *p) : node(p) {}
    It(const It &o) : node(o.node) {}
    bool operator!=(const It &o) const { return node != o.node; }
    It operator++(int) { It tmp(*this); node = node->next; return tmp; }
};
extern "C" void func_001E2EB0(void *);
extern "C" void func_001FEE48(char *, void *) throw();
extern "C" int func_00200040(void *) throw();
extern "C" int func_00200048(void *, int) throw();
extern "C" int func_0022F1D8();
extern "C" void func_00200078(Obj *self) {
    int i = 0;
    int n = func_00200040(self);
    for (; i < n; i++) func_001E2EB0((void *)func_00200048(self, i));
    self->state = 1;
    func_001FEE48((char *)self, (void *)func_0022F1D8());
    It first(self->head->next);
    It last(self->head);
    while (first != last) { first.node->value = 0; first++; }
}
