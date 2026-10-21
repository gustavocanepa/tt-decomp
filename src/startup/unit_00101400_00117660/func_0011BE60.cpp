/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
typedef long s64;
typedef unsigned int u32;
static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct B4 { char p[0xA0]; f32 times[40]; int values[40][2]; int a280[2]; };
struct Elem { char p0[8]; int f8; char p1[4]; u32 f10; char p2[0x4994 - 0x14]; };
struct Item { char p0[4]; int f4; int f8; };
struct Rec { char p[0x14C]; Item *items; char q[0x80]; int f1D0; };
struct Ent { Elem *ptr; int pad; };
struct Info { char p0[12]; char pad[0x50]; Ent ent[2]; };
struct Box { char p[0x68]; int n; };
struct E { short d, p; Box *(*f)(char *); };
struct V { char p[0x90]; E e; };
struct Dev { char p[0x64]; V *v; char q[4]; int f6C; };
struct Dest {
    char p0[4];
    int a4[0x9F];
    f32 f2E4_pad;
};
struct Out {
    char p0[4];
    char arr[0x280 - 4];
    int a280[2];
    char p1[0x290 - 0x288];
    long long q290[2];
    char p2[0x2CC - 0x2A0];
    f32 f2CC;
    char p3[0x2E4 - 0x2D0];
    f32 f2E4;
    char p4[4];
    f32 f2EC;
    char p5[0x2F8 - 0x2F0];
    f32 f2F8, f2FC, f300;
    int n304;
};
extern Dev *D_005797E0;
extern "C" Rec *func_0011C628(int);
extern "C" f32 func_00375B48(int, int);

extern "C" void func_0011BE60(char *arg0) {
    Dev *d = D_005797E0;
    int sp0 = d->f6C;
    E *e = &d->v->e;
    Box *o = e->f((char *)d + e->d);
    Info *info = (Info *)o;
    int k;
    int n = o->n;
    int cnt = n + 1;
    int mn = cnt;
    Out *out = (Out *)arg0;
    for (k = 0; k < 2; k++) {
        int a;
        for (a = 0; a < cnt; a++) {
            Elem *el = info->ent[k].ptr + a;
            if (el->f8 == 0) break;
        }
        if (a != 0) mn = a < mn ? a : mn;
        Elem *el = info->ent[k].ptr + n;
        out->q290[k] = el->f10;
    }
    out->n304 = mn;
    f32 prev = -1.0f;
    f32 acc = 0.0f;
    int i = 0;
    if (mn > 0) {
        char *base = arg0 + 4;
        f32 *dst = (f32 *)(arg0 + 0xA4);
        int off = 0;
        char *p5 = base;
        do {
            int j = 0;
            do {
                Rec *r = func_0011C628(j);
                if (r->f1D0 == 0) {
                    Item *it = (Item *)((char *)r->items + off);
                    ((B4 *)base)->values[i][j] = it->f4;
                    ((B4 *)base)->a280[j] += it->f8;
                }
                j++;
            } while (j < 2);
            f32 v;
            if (i != 0) v = func_00375B48(sp0, i - 1); else v = 0.0f;
            v = v + acc;
            if (v <= prev) {
                f32 s = out->f300;
                acc += s;
                v += s;
            }
            *dst = v;
            dst++;
            prev = v;
            off += 0x4994;
            p5 += 8;
            i++;
        } while (i < out->n304);
    }
    f32 w = out->f2FC - out->f2F8;
    out->f300 = w;
    out->f2E4 = minf(maxf(out->f2EC / w, 0.4f), 10.0f);
    out->f2CC = w * 0.5f;
}
