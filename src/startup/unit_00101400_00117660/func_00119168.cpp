#include "types.h"

struct VEntry { short delta; short index; void (*fn)(void *, void *); };
struct Tgt { char pad0[4]; char *vtbl; };
struct B16 {
    s32 w[4];
    B16(s32, s32, s32) __asm__("func_0011DDE8");
};
struct A0 { char pad[0x80]; Tgt *f80; };

extern s32 D_005797E0;
extern char D_005E0070[];
extern char D_005E0080[];

extern "C" s32 func_00357310(const char *);

extern "C" void func_00119168(A0 *arg0, Tgt **arg1) {
    Tgt *t = *arg1;
    arg0->f80 = t;
    if (t != 0) {
        s32 a = func_00357310(D_005E0070);
        B16 buf(D_005797E0, a, func_00357310(D_005E0080));
        Tgt *u = *arg1;
        VEntry *e = (VEntry *)(u->vtbl + 0x370);
        e->fn((char *)u + e->delta, &buf);
    }
}
