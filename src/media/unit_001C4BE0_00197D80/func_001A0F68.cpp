typedef short s16;
typedef int s32;

extern char D_00579F50[];
extern char D_00579F48[];

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[0x4C];
    char *sub;
};

extern "C" char *func_001A0F68(Obj *arg0) {
    char *res;
    VEntry *e = (VEntry *)(arg0->sub + 0xD0);

    if (e->fn((char *)arg0 + e->delta) != 0) {
        res = D_00579F50;
    } else {
        res = D_00579F48;
    }
    return res;
}
