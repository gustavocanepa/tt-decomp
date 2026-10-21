typedef int s32;
typedef float f32;
typedef signed char s8;

struct Inner {
    char pad0[0x624];
    union {
        f32 f;
        s32 i;
    } u608;
    s8 b60C;
    s8 b60D;
};

struct Tab {
    char pad0[0xAC];
    f32 a74;
    f32 a78;
    f32 a7c;
};

extern "C" Tab D_007672C8;

extern "C" f32 func_002F4C28(char *self, s32 *a1, f32 *a2, s32 *a3, s32 *a4) {
    Inner *w = (Inner *)(self + 0x104);
    if (a2 != 0) {
        *a2 = 1.0f;
    }
    if (a3 != 0) {
        *a3 = w->b60C;
    }
    if (a4 != 0) {
        *a4 = w->b60D;
    }
    Tab *t = &D_007672C8;
    f32 f1 = w->u608.f * t->a74;
    if (w->b60C == 2) {
        w->u608.i = 0;
    }
    if (a1 != 0) {
        s32 v = 0;
        if (t->a7c < f1) {
            v = 2;
        } else if (t->a78 < f1) {
            v = 1;
        }
        *a1 = v;
    }
    return f1;
}
