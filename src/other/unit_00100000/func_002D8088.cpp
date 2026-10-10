struct Node {
    char pad0[0x10];
    Node *next;
};

struct List {
    char pad0[0x14];
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

extern "C" Node *func_002D8088(Obj *self) {
    Node *n = self->ctx->list->first;
    for (;;) {
        if (!n)
            return 0;
        if (func_002D7F68(self, n))
            return n;
        n = n->next;
    }
}
