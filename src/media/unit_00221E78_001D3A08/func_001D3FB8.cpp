extern "C" void func_001D35A0(void *);
extern "C" void func_001D3548(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_0029CEF0(void *, int);
extern "C" int func_0029E9F0(int);

struct VEntry { short delta; short index; void (*fn)(void *, int); };
struct VObj { char pad0[4]; char *vtbl; };

struct A {
    VObj *p;
    int pad[3];
};
struct B {
    int v[4];
};
static inline int get(B *b) { return b->v[0]; }

extern "C" void func_001D3FB8(void *arg0, void *arg1, int count, void *name)
{
    if (count > 0) {
        A a;
        B b;
        func_001D35A0(&a);
        func_0029CF48(&b, name);
        VObj *o = a.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x208);
        char *self = (char *)o + e->delta;
        int arg = func_0029E9F0(get(&b)) != 0;
        e->fn(self, arg);
        func_0029CEF0(&b, 2);
        func_001D3548(&a, 2);
    }
}
