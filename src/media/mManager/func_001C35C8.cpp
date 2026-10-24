/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
extern "C" void func_001C2A20(void *, int) throw();
extern "C" void func_001C2A78(void *) throw();
extern "C" void func_001CC068(void *, void *, int);
extern "C" void func_001DD5B0(void *, int);
extern "C" void func_001DD608(void *, void *);

extern "C" void func_001C35C8(int a0, int a1, int mode, Obj *o) {
    void *sp0[4];
    char sp10[16];
    if (mode > 0) {
        func_001C2A78(sp0);
        func_001DD608(sp10, o);
        int flag = 1;
        if (mode == 2) {
            Obj *c = *(Obj **)((char *)o + 4);
            VEntry *e = (VEntry *)(c->vtbl + 0x68);
            flag = e->fn((char *)c + e->delta) != 0;
        }
        func_001CC068(sp0[0], sp10, flag);
        func_001DD5B0(sp10, 2);
        func_001C2A20(sp0, 2);
    }
}
