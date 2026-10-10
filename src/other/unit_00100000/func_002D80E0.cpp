struct Node {
    char pad0[0xC];
    Node *next;
};

struct List {
    char pad0[0x18];
    Node *first;
};

struct Ctx {
    char pad0[0x60];
    List *list;
};

struct Obj {
    char pad0[0xC];
    Ctx *ctx;
};

extern "C" int func_002D7F68(Obj *self, Node *node);

extern "C" Node *func_002D80E0(Obj *self) {
    Node *n = self->ctx->list->first;
    for (;;) {
        if (!n)
            return 0;
        if (func_002D7F68(self, n))
            return n;
        n = n->next;
    }
}
