/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct P { f32 a; f32 b; };
struct N { char p[0x8C]; N *next; P pos; };
struct C { P p; s32 c; };
extern "C" s32 func_0043C600(C *, N *, N *);
extern "C" N *func_0043C740(s32 arg0, N *list, N *ref) {
    N *best2 = 0;
    N *best1 = ref;
    C c;
    P *src = &ref->pos;
    c.p.a = src->a;
    c.p.b = src->b;
    c.c = arg0;
    for (N *n = list; n != 0; n = n->next) {
        if (n != ref) {
            if (func_0043C600(&c, ref, n)) {
                if (func_0043C600(&c, n, best2)) best2 = n;
            }
            if (func_0043C600(&c, n, best1)) best1 = n;
        }
    }
    if (best2) return best2;
    return best1;
}
