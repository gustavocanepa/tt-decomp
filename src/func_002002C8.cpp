/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next, *prev; int value; };
struct Obj { char pad[0x1C]; Node *head; };
struct Iter {
    Node *p;
    Iter(Node *n):p(n) {}
    Iter(const Iter &o):p(o.p) {}
    void advance() { p = p->prev; }
};
extern "C" void func_002002C8(Obj *self) {
    Iter it(self->head);
    it.advance();
    it.p->value = 0;
}
