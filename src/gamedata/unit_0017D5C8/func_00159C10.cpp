/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[16]; void *list; int pad14; int dirty; };
struct VE { short delta; short index; int (*fn)(void *); };
struct VO { int x; VE *vt; };
static inline int vcall(VO *o) {
    VE *e = (VE *)((char *)o->vt + 0x68);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_001596F8(void *, int) throw();
extern "C" void func_00159750(void *, void *) throw();
extern "C" void func_00198598(void *, int);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029EA18(void *, int);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);
extern "C" void func_00159C10(void **arg0, void *arg1, int arg2, VO **arg3) {
    Node *h[4];
    void *buf[4];
    bool result = false;
    func_00159750(h, arg1);
    if (arg2 > 0) {
        int index = vcall(*arg3);
        if (index >= 0) {
            func_00198598(h[0]->list, index);
            h[0]->dirty = 1;
            result = true;
        }
    }
    void **p = buf;
    func_0029EA18(p, result);
    if (arg0 != p) {
        void *n = *p;
        if (n != 0) func_002C0FE8(n);
        void *old = *arg0;
        if (old != 0) func_002C1050(old);
        *arg0 = n;
    }
    func_0029CEF0(p, 2);
    func_001596F8(h, 2);
}
