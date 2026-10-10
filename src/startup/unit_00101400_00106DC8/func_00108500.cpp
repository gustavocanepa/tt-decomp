typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Obj {
    char pad[0x64];
    char *vtbl;
};

extern s32 D_0057973C;
extern Obj *D_00579740;

extern "C" s32 func_004A4530(void);
extern "C" s32 func_004A45F8(s32);
extern "C" void func_004A45D0(s32);
extern "C" void func_00108118(void);

extern "C" void func_00108500(void) {
    if (D_0057973C == 0) {
        D_0057973C = 1;
        s32 r = func_004A45F8(func_004A4530() - 0x100000);
        func_00108118();
        Obj *o = D_00579740;
        VEntry *e = (VEntry *)(o->vtbl + 0x10);
        e->fn((char *)o + e->delta);
        func_004A45D0(r);
    }
}
