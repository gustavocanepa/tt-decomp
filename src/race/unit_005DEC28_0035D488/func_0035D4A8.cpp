typedef short s16;
typedef int s32;

struct VEntry003A8338 {
    s16 delta;
    s16 index;
    void (*fn)(void *, float, float);
};

struct Obj003A8338 {
    char pad0[0x100];
    char sub[0x14];
    VEntry003A8338 *unk114;
};

extern "C" void func_0035D4A8(char *arg0, int arg1) {
    char *a2 = arg0 + 0x104;
    VEntry003A8338 *e = (VEntry003A8338 *)((char *)*(void **)(a2 + 0x14) + 0x50);

    e->fn(a2 + e->delta, 0.0f, (float)arg1);
}
