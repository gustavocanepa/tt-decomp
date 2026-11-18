/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj {
    s32 field0;
    char *vtbl;
};
struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, void *, s32, s32);
};
struct StackFrame {
    char first[0x10];
    Obj *object;
    char pad[0xC];
};

extern char D_0057C6E0[];
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A9580(Obj *, void *, void *);
extern "C" void func_002A7A30(void *);
extern "C" void func_002B1578(void *, int) throw();
extern "C" void func_002B15D0(void *, void *) throw();

extern "C" void func_002B1758(void *arg0, Obj **arg1, s32 arg2, s32 arg3) {
    StackFrame sp;
    func_002B15D0(&sp, arg1);
    Obj **p = &sp.object;
    func_002A7A30(p);
    func_002A9580(*arg1, p, D_0057C6E0);
    Obj *o = *p;
    VEntry *e = (VEntry *)(o->vtbl + 0xB8);
    e->fn((char *)o + e->delta, &sp, arg2, arg3);
    func_002A75A8(p, 2);
    func_002B1578(&sp, 2);
}
