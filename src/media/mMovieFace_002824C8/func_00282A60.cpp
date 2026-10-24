/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct RefCounter;
struct VEntry { s16 delta; s16 pad; void (*fn)(void *, void *, s32, void *); };
struct Vt { char pad[4]; VEntry *vtbl; };
struct Obj {
    char pad0[0xE4];
    Vt *unkC8;
    s32 unkCC;
};

extern "C" void func_001EDBE0(void *, s32);
extern "C" void func_001EEB30(s32, const char *);
extern "C" void func_001EEDE8(void *);
extern "C" s32 func_001D9CC0(void *);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002A7578(void *, void *);
extern "C" void func_002A75A8(void *, s32);
extern "C" void func_002A7A30(void *);
extern "C" void func_002C0FE8(RefCounter *);
extern "C" void func_002C1050(RefCounter *);

extern char D_005F0398[];

static inline void assign(s32 *dst, s32 *src) {
    if (dst != src) {
        s32 n = *src;
        if (n != 0)
            func_002C0FE8((RefCounter *)n);
        s32 old = *dst;
        if (old != 0)
            func_002C1050((RefCounter *)old);
        *dst = n;
    }
}

struct Value { s32 p; Value() { func_002A7A30(this); } };
extern "C" void func_00282A60(Obj *self, s32 a1, s32 a2) {
    s32 a[4];
    if (a2 != 0) {
        func_001EEDE8(a);
        func_001EEB30(a[0], D_005F0398);
        func_001EDBE0(a, 2);
    }
    Vt **handle;
    if (func_001D9CC0(self) != 0 && *(handle = &self->unkC8) != 0) {
        func_002A7A30(a);
        Value b[2];
        s32 tmp[4];
        s32 *d = tmp;
        Value *dst = b;
        s32 t = a1;
        func_002A7578(d, &t);
        assign(&dst->p, d);
        func_002A75A8(d, 2);
        dst = &b[1];
        func_0029EA18(d, self->unkCC);
        assign(&dst->p, d);
        func_0029CEF0(d, 2);
        Vt *o = *handle;
        VEntry *e = o->vtbl + 0xC0 / 8;
        e->fn((char *)o + e->delta, a, 2, b);
        Value *p = b+2;
        while (b != p) {
            --p;
            func_002A75A8(p, 2);
        }
        func_002A75A8(a, 2);
    }
}
