typedef int s32;
typedef short s16;
typedef float f32;

struct VEntryD8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntry118 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" f32 func_00417078(void);
extern "C" f32 func_00318380(s32 x);

extern "C" f32 func_0031A5B8(char *arg0) {
    f32 r = func_00417078();
    s32 a = *(s32 *)(arg0 + 0xA4C);
    VEntryD8 *e = (VEntryD8 *)(*(char **)arg0 + 0xE0);
    char *r2 = (char *)e->fn(arg0 + e->delta, a);
    if (r2 != 0) {
        VEntry118 *g = (VEntry118 *)(*(char **)r2 + 0x128);
        r = func_00318380(g->fn(r2 + g->delta));
    }
    return r;
}
