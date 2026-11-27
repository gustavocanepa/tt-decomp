/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, const char *); };
struct Obj { char pad0[4]; char *vtbl; };
struct Hold { Obj *p; char pad[12]; };
struct Hold2 { s32 *p; char pad[12]; };

extern char D_005EA618[];

extern "C" void func_001EEF60(void *, int) throw();
extern "C" void func_001EEFB8(void *, void *) throw();
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029EA18(void *, s32);
extern "C" void func_002ADBF0(void *, int);
extern "C" void func_002ADC48(void *, void *);
extern "C" Str *func_002AFE68(void *);
extern "C" void func_002C0FE8(s32);
extern "C" void func_002C1050(s32);

static inline const char *c_str(Str *s) {
    s32 len = ((Rep *)s->p)[-1].len;
    if (len == 0) {
        return D_005EA618;
    }
    s->p[len] = 0;
    return s->p;
}

extern "C" void func_001EFD88(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 > 0) {
        Hold sp0;
        Hold2 a;
        Hold2 b;
        func_001EEFB8(&sp0, arg1);
        Hold2 *pa = &a;
        func_002ADC48(pa, arg3);
        Obj *o = sp0.p;
        VEntry *e = (VEntry *)(o->vtbl + 0x1F8);
        s16 d = e->delta;
        void *adj = (char *)o + d;
        Str *str = func_002AFE68(pa->p);
        const char *cs = c_str(str);
        int result = e->fn(adj, cs) != 0;
        Hold2 *pb = &b;
        func_0029EA18(pb, result);
        if ((void *)arg0 != (void *)pb) {
            s32 nv = (s32)pb->p;
            if (nv != 0) func_002C0FE8(nv);
            if (*arg0 != 0) func_002C1050(*arg0);
            *arg0 = nv;
        }
        func_0029CEF0(pb, 2);
        func_002ADBF0(pa, 2);
        func_001EEF60(&sp0, 2);
    }
}
