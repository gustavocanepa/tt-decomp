/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { char pad[4]; char *vt; };
struct ESet { short delta, index; void (*fn)(void *, int); };
struct EGet { short delta, index; int (*fn)(void *); };
struct A { VObj *p; int pad[3]; };
static inline int get(VObj *o) {
    EGet *e = (EGet *)(o->vt + 0x68);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_001D35A0(void *, void *) throw();
extern "C" void func_001D3548(void *, int) throw();
extern "C" void func_001D4EC0(void *arg0, void *arg1, int count, VObj **args) {
    A a;
    func_001D35A0(&a, arg1);
    VObj *o = a.p;
    ESet *e = (ESet *)(o->vt + 0x1E8);
    char *self = (char *)o + e->delta;
    e->fn(self, get(args[0]));
    func_001D3548(&a, 2);
}
