/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VObj;
struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { char pad0[4]; char *vtbl; };
struct H { VObj *p; };
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_0021F580(void *, int) throw();
extern "C" void func_0021F5D8(void *, void *) throw();
extern "C" void func_0021FE18(void *, s32);
extern "C" void func_0021F7D0(void *unused, void *a1, s32 a2, void *a3) {
    H h;
    s32 s1 = 0;
    if (a2 > 0) {
        func_002027E0(&h, a3);
        s1 = (s32)h.p;
        func_00202788(&h, 2);
    }
    func_0021F5D8(&h, a1);
    VEntry *e = (VEntry *)(h.p->vtbl + 0x268);
    e->fn((char *)h.p + e->delta);
    func_0021FE18(h.p, s1);
    func_0021F580(&h, 2);
}
