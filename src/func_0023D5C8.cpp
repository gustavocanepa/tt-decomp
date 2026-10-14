/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob {
    short d[0x57];
};

struct Inner;

struct VEnt {
    short adj;
    short pad;
    Blob (*fn)(Inner *);
};

struct VTab {
    char pad[0x10];
    VEnt e;
};

struct Inner {
    VTab *vt;
};

struct Node {
    char pad0[0x10];
    Inner *in;
    Blob b;
};

extern "C" void func_004C9CC0(void *, int, int, int, int);

extern "C" void func_0023D5C8(Node *self) {
    Inner *x = self->in;
    if (x) {
        VEnt *e = &x->vt->e;
        self->b = e->fn((Inner *)((char *)x + e->adj));
    } else {
        func_004C9CC0(&self->b, 0, 0, 0, 0);
    }
}
