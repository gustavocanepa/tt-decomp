typedef int s32;

struct G { s32 m0; s32 m4; void *h; };
extern G D_0076A008;
extern "C" void func_004C4588(void *);

extern "C" void func_0042C490(void) {
    G *g = &D_0076A008;
    if (g->h != 0) {
        func_004C4588(g->h);
        g->h = 0;
    }
    g->m0 = -1;
}
