/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;

struct Out {
    s32 w0;
    s32 w4;
    f32 f8;
};

struct VA {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, s32 a1);
};

struct VB {
    s16 delta;
    s16 index;
    void (*fn)(void *self, void *a1);
};

extern "C" s32 func_00320468(char *arg0, s32 u1, s32 u2, s32 arg3, s32 flags, Out *out)
{
    s32 s0 = flags;
    char *obj = arg0 + arg3 * 0x1B4;
    char *s2 = obj + 0x10;
    VA *ea = (VA *)(*(char **)arg0 + 0xE0);
    s32 cur = *(s32 *)(s2 + 0x170);
    s32 r = ea->fn(arg0 + ea->delta, arg3);
    char *s2b = s2;
    s32 c = (r != cur);
    if ((s0 & 2) != 0) {
        c = 1;
    }
    if ((s0 & 4) != 0) {
        c = 1;
    }
    if (c != 0) {
        char *x = (char *)cur;
        VB *eb = (VB *)(*(char **)x + 0x148);
        eb->fn(x + eb->delta, s2b);
        *(char **)(s2 + 0x144) = x;
        out->w0 = 1;
        out->f8 = 0.5f;
        return 0;
    }
    return c;
}
