/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct VE0 { short d; short i; u32 (*fn)(void *); };
struct VE1 { short d; short i; void *(*fn)(void *, u32); };
struct VT { char pad0[0x10]; VE1 get; VE0 size; };
struct Obj { VT *vt; };

extern "C" int HOutput__printf(void *, const char *, ...);
extern "C" void *HOutput__operator_inc(void *);
extern "C" void *HOutput__operator_dec(void *);
extern "C" s32 func_002BCC70(void *) throw();
extern "C" s32 func_002BCC80(void *) throw();
extern "C" void func_002BD000(void *, void *) throw();
extern "C" double func_004B4C18(f32);
extern char D_005F1F98[];
extern char D_005F1E90[];
extern char D_005F1FB0[];

extern "C" void ADHOC__PoolAllocator__dump(Obj *self, void *out) {
    u32 b = 0;
    u32 i = 0;
    u32 a = 0;
    u32 n;
    VE0 *vs = &self->vt->size;
    n = vs->fn((char *)self + vs->d);
    if (n != 0) {
        do {
            VE1 *g;
            HOutput__printf(out, D_005F1F98, i);
            HOutput__operator_inc(out);
            g = (VE1 *)((char *)self->vt + 0x10);
            func_002BD000(g->fn((char *)self + g->d, i), out);
            HOutput__operator_dec(out);
            HOutput__printf(out, D_005F1E90);
            g = (VE1 *)((char *)self->vt + 0x10);
            b += func_002BCC70(g->fn((char *)self + g->d, i));
            g = (VE1 *)((char *)self->vt + 0x10);
            u32 j = i;
            i++;
            a += func_002BCC80(g->fn((char *)self + g->d, j));
        } while (i < n);
    }
    const char *fmt = D_005F1FB0;
    double ratio = func_004B4C18((f32)b / (f32)a * 100.0f);
    HOutput__printf(out, fmt, n, b, a, ratio);
}
