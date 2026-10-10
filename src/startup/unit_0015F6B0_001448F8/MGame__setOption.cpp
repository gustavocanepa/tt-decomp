extern "C" void func_00141FF0(void *a);
extern "C" void func_00141F98(void *a, int in_chrg);
extern "C" void *func_0015A6E8(void *b, void *name);
extern "C" void func_0015A690(void *b, int in_chrg);
extern "C" void func_004010E0(void *dst, void *src);
extern "C" void func_003FCC50(void *obj);

struct Node {
    char pad0[0x10];
    void *obj;
};

struct Handle {
    Node *p;
    int pad[3];
    void *get() { return p->obj; }
};

extern "C" void MGame__setOption(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        Handle a;
        Handle b;
        func_00141FF0(&a);
        func_0015A6E8(&b, name);
        func_004010E0(a.get(), b.get());
        func_003FCC50(b.get());
        func_0015A690(&b, 2);
        func_00141F98(&a, 2);
    }
}
