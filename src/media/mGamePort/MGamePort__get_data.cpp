/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(void *);
};

struct VTab {
    char pad[0x20];
    VEnt e;
};

struct Inner {
    VTab *vt;
};

struct Blob {
    short d[0x57];
};

struct Node {
    char pad0[0x10];
    s32 v10;
    Blob b;
};

struct Src {
    char pad0[0x10];
    Inner *in;
    Blob b;
};

extern "C" void func_0023CBF8(void *, int);
extern "C" void func_0023CD28(void *);
extern "C" void func_0023D928(void *, int);
extern "C" void func_0023D980(void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

extern "C" void MGamePort__get_data(void **arg0) {
    Src *a[4];
    Node *b[4];
    func_0023D980(a);
    Node **pb = b;
    func_0023CD28(pb);
    Node *d = pb[0];
    Src *s = a[0];
    Inner *in = s->in;
    VEnt *e = &in->vt->e;
    d->v10 = e->fn((char *)in + e->adj);
    d->b = s->b;
    if (arg0 != (void **)pb) {
        Node *nv = pb[0];
        if (nv != 0)
            func_002C0FE8(nv);
        if (*arg0 != 0)
            func_002C1050(*arg0);
        *arg0 = nv;
    }
    func_0023CBF8(pb, 2);
    func_0023D928(a, 2);
}
