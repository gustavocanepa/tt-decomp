struct Node { char pad[0x1A8]; int value; };
struct Item { Node *node; char pad[0x1B4 - 4]; };
struct Obj { char pad[0x174]; Item items[6]; };
extern "C" void func_0031C6C0(Obj *o, int v) {
    int i;
    for (i = 0; i < 6; i++) {
        Item *it = &o->items[i];
        Node *n = it->node;
        if (n)
            n->value = v;
    }
}
