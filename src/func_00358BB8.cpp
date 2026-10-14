/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Event {
    int a;
    int pad4;
    int c;
    int b;
};

static inline int clamp(int v, int lo, int hi) { return v < lo ? lo : (v > hi ? hi : v); }

struct Packed {
    unsigned int a : 4;
    unsigned int b : 2;
    int c : 26;
};

union Word {
    Packed p;
    unsigned int w;
};

extern "C" unsigned int RaceDisplayDiffEvent__encode(Event *e, int unused, int unused2, unsigned int w) {
    Word u;
    u.w = w;
    int a = clamp(e->a, 0, 15);
    u.p.a = a;
    u.p.b = e->b;
    int c = clamp(e->c, -0x1FFFFFF, 0x1FFFFFF);
    u.p.c = c;
    return u.w;
}
