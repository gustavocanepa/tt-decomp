/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;
struct Item { float x, y, z; short link; short pad; };
struct Node { char pad[8]; u32 info; };
struct Query { u16 node; short flag; };
struct Obj {
    char pad[0x78];
    Node *nodes;
    char pad7C[8];
    Item *items;
    char pad88[4];
    short *index;
};
typedef void (*Callback)(Item *, int, int);

static inline int outcode(const float *p, float x0, float z0, float x1, float z1) {
    int c = 0;
    float px = p[0];
    float pz = p[2];
    if (px < x0) c = 1;
    if (x1 < px) c |= 2;
    if (pz < z0) c |= 4;
    if (z1 < pz) c |= 8;
    return c;
}

extern "C" void func_00385138(Obj *o, Query *q, Callback cb, int arg, float x0, float z0, float x1, float z1) {
    if (q->flag >= 0) {
        Node *n0 = (Node *)((char *)o->nodes + q->node * 12);
        u32 info = n0->info;
        int start = info & 0xFFFFFF;
        int end = start + (info >> 24);
        for (int i = start; i < end; i++) {
            Item *it = (Item *)((char *)o->items + o->index[i] * 0x10);
            int c0 = outcode(&it->x, x0, z0, x1, z1);
            if (c0 != 0) {
                Item *n = it + 1;
                if (it->link < 0) n = n + it->link;
                int c1 = outcode(&n->x, x0, z0, x1, z1);
                if (c0 & c1) continue;
            }
            cb(it, arg, c0);
        }
    }
}
