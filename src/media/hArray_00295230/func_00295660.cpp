typedef int s32;
typedef short s16;

struct VE {
    s16 delta;
    s16 index;
    void *fn;
};

extern "C" void func_002A7590(void *h, s32 val);
extern "C" void func_002A75A8(void *h, s32 flags);

static inline s32 get70(void *o, s32 n) {
    VE *e = (VE *)(*(char **)((char *)o + 4) + 0x88);
    return ((s32 (*)(void *, s32))e->fn)((char *)o + e->delta, n);
}

static inline void set78(void *o, s32 a, s32 b) {
    VE *e = (VE *)(*(char **)((char *)o + 4) + 0x90);
    ((void (*)(void *, s32, s32))e->fn)((char *)o + e->delta, a, b);
}

extern "C" void func_00295660(void *arg0, s32 arg1, s32 arg2) {
    s32 tmp[4];

    if (arg1 < arg2) {
        s32 i = arg1;
        func_002A7590(tmp, get70(arg0, arg1));
        do {
            s32 n = i + 1;
            s32 v = get70(arg0, n);
            set78(arg0, i, v);
            i = n;
        } while (i < arg2);
        set78(arg0, arg2, (s32)tmp);
        func_002A75A8(tmp, 2);
    }
    if (arg2 < arg1) {
        s32 i;
        func_002A7590(tmp, get70(arg0, arg1));
        i = arg1;
        do {
            s32 n = i - 1;
            s32 v = get70(arg0, n);
            set78(arg0, i, v);
            i = n;
        } while (arg2 < i);
        set78(arg0, arg2, (s32)tmp);
        func_002A75A8(tmp, 2);
    }
}
