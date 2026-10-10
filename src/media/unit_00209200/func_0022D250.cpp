struct Handle {
    void *p;
    Handle(const Handle &h) __asm__("func_0022C0D0");
    Handle(void *const &ptr) __asm__("func_0022C0B8");
};

struct Node {
    char pad[0x14];
    Handle value;
};

struct Iter {
    Node *node;
    Iter() {}
    Iter(Node *n) : node(n) {}
    Iter(const Iter &i) : node(i.node) {}
};

static inline bool operator==(const Iter &a, const Iter &b) { return a.node == b.node; }

struct Map {
    int m0;
    Node *header;
    Iter end() { return Iter(header); }
};

struct Obj {
    char pad[0x20];
    Map map;
};

extern "C" Iter func_00538BF8(Map *m);

Handle func_0022D250(Obj *o) __asm__("func_0022D250");

Handle func_0022D250(Obj *o) {
    Iter it = func_00538BF8(&o->map);
    if (!(it == o->map.end()))
        return it.node->value;
    return Handle(0);
}
