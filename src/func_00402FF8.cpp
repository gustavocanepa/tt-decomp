/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef signed char s8;
struct Src { u8 b0, b1, b2; u8 p3[5]; u8 b8; char b9; u8 bA, bB, pC, bD, bE, bF; };
struct Dst {
    int p0; int flags; short h8; u8 bA, bB, bC, bD, bE; char bF; u8 b10, b11, b12, b13, b14;
    char pad[3]; char p18[0x30]; char p48[0x1C]; char p64[0x28]; char p8C[0x10];
};
static inline int clamp(int x) { if (x >= 0x100) x = 0xFF; return x; }
extern "C" {
s8 func_00403DA8(void *, int) throw();
s8 func_00404138(void *, int) throw();
s8 func_00404528(void *, int) throw();
s8 func_00404980(void *, int) throw();
static inline bool active(Dst *d) { return func_00403DA8(d->p18, 0) != 0; }
void *func_00402FF8(Dst *d, Src *s) {
    int ok;
    d->h8 = 0xE;
    if (active(d)) {
        int v0 = s->b0;
        int v1 = s->b1;
        if (v0 >= 0x100) v0 = 0xFF;
        if (v1 >= 0x100) v1 = 0xFF;
        d->bA = v0;
        d->bB = v1;
    } else {
        d->bA = 0;
        d->bB = 0;
    }
    ok = 0;
    switch (d->flags & 0xF) {
    case 1:
        ok = func_00404138(d->p48, 0) != 0;
        break;
    case 2:
        ok = func_00404528(d->p64, 0) != 0;
        break;
    case 3:
        ok = func_00404980(d->p8C, 0) != 0;
        break;
    }
    if (ok) {
        d->bC = s->b2;
        d->bD = 0;
        d->bE = s->b8;
        { int t9 = s->b9; d->bF = t9; }
        d->b10 = s->bA;
        d->b11 = s->bB;
        d->b12 = s->bD;
        d->b13 = s->bE;
        d->b14 = s->bF;
    } else {
        d->bC = 0;
        d->bD = 0;
        d->bE = 0;
        d->bF = 0;
        d->b10 = 0;
        d->b11 = 0;
        d->b12 = 0;
        d->b13 = 0;
        d->b14 = 0;
    }
    return &d->h8;
}
}
