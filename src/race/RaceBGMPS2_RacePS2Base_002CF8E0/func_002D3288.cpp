typedef int s32;
typedef short s16;
typedef float f32;

struct VE_00340470 {
    s16 delta;
    s16 index;
    void *fn;
};

extern "C" f32 func_002D3288(void *arg0, f32 fparg0) {
    char *self = (char *)arg0;
    f32 maxv = 0.0f;

    char *blk = *(char **)(*(char **)(self + 0x6C) + 0x60);
    VE_00340470 *e1 = (VE_00340470 *)(*(char **)(self + 0x64) + 0xD0);
    char *s2 = ((char *(*)(char *, s32))e1->fn)(self + e1->delta, 0);

    char *n = *(char **)(blk + 0x10);
    while (n != 0) {
        VE_00340470 *e2 = (VE_00340470 *)(*(char **)(self + 0x64) + 0x4C8);
        s32 ok = ((s32 (*)(char *, char *, char *, f32))e2->fn)(self + e2->delta, n, s2, fparg0);
        if (ok != 0) {
            char *a = *(char **)(n + 0x4840);
            VE_00340470 *e3 = (VE_00340470 *)(*(char **)(a + 8) + 0x188);
            f32 t = ((f32 (*)(char *, f32))e3->fn)(a + e3->delta, fparg0);
            if (maxv < t) {
                maxv = t;
            }
        }
        n = *(char **)(n + 4);
    }
    return maxv;
}
