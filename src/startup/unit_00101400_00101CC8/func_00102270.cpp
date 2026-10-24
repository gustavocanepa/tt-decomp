#include "types.h"

struct Entry {
    short delta;
    short pad;
    void (*fn)(float *, void *);
};

extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_00475780(float arg0);
extern "C" void func_00477E30(float arg0, float arg1, float arg2, float arg3);
extern "C" void func_0046D810(s32 arg0, char *arg1, char *arg2, s32 arg3, s32 arg4, s32 arg5);

extern char D_00579380[];
extern char D_005793C0[];

extern "C" void func_00102270(char *arg0) {
    float v[4];
    char *c;
    Entry *e;

    func_00473050();
    c = *(char **)(arg0 + 0x9C);
    e = (Entry *)((char *)*(void **)c + 0x30);
    e->fn(v, c + e->delta);
    func_00477E30(v[0], v[1], v[2], v[3]);
    func_00475780(-*(float *)(arg0 + 0xB0));
    func_0046D810(4, D_00579380, D_005793C0, 0, 0, 0);
    func_004730A8();
}
