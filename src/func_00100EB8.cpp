typedef int s32;
typedef short s16;
typedef unsigned short u16;

struct S {
    char pad[0xB0];
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(S *, char *);
};

extern s32 D_00578EEC;
extern s32 D_00578EBC;
extern s32 D_00578EC0;
extern u16 D_00578EC8[];
extern s32 D_00578E20;
extern s32 D_00583EF0;
extern char D_00598730[];

extern "C" void *func_004C9C50(S *arg0);
extern "C" int func_004C9AB8(void *dev, int reg);

extern "C" void func_00100EB8(void) {
    S buf;
    VEntry *e = (VEntry *)(*(char **)D_00598730 + 0x10);
    e->fn(&buf, D_00598730 + e->delta);

    s32 v = func_004C9AB8(func_004C9C50(&buf), 0);
    s32 prev = D_00578EEC;
    s32 a1 = (prev ^ v) & v;

    if (D_00578EBC == 0) {
        s32 a2 = D_00578EC0;
        if (D_00578EC8[a2] == 0) {
            D_00578EC0 = 0;
            D_00578EBC = 1;
        } else if (a1 != 0) {
            if (a1 == D_00578EC8[a2]) {
                D_00578EC0 = a2 + 1;
            } else {
                D_00578EC0 = 0;
            }
        }
    } else {
        D_00578E20 = 0;
        if (v == 0x1000) {
            D_00578E20 = 1;
        }
        switch (a1) {
        default:
            break;
        case 1:
            D_00578EBC = 0;
            D_00578E20 = 0;
            break;
        case 0x400:
            D_00583EF0 ^= 1;
            break;
        }
    }
    D_00578EEC = v;
}
