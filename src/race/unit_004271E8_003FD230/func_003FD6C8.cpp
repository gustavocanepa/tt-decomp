typedef short s16;
typedef int s32;

extern "C" s32 func_00403568(s32);
extern "C" s32 func_00403570(s32, s32);

extern char D_005FA5A0[];

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, char *, s32);
};

struct Holder {
    char pad0[0x50];
    VEntry ent;
};

extern "C" void func_003FD6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s1 = arg0 + 0x1238;
    if (arg1 < func_00403568(s1)) {
        s32 *pv = (s32 *)func_00403570(s1, arg1);
        Holder *h = (Holder *)*pv;
        VEntry *e = &h->ent;
        e->fn((char *)pv + e->delta, D_005FA5A0, arg3);
    }
}
