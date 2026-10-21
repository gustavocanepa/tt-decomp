#include "types.h"

extern "C" void func_002E45F8(void *p);
extern "C" void func_002F35C0(void *a, void *b, s32 c, s32 d);
extern "C" void func_002ED0B0(void *self, void *a, void *b, s32 c);
extern "C" void func_002F3A88(void *a, f32 *b, void *c);
extern "C" void func_002EDC38(void *a, void *b, s32 c);
extern "C" f32 func_002FABA0(void *p);

extern "C" s32 func_002EDD90(void *arg0, s32 arg1, f32 *arg2, void *arg3) {
    char buf0[0xE0];
    char buf1[0x100];
    char buf2[0x20];
    f32 t;
    f32 v;

    func_002E45F8(buf2);
    if (arg3 == 0) {
        arg3 = buf2;
    }
    func_002F35C0(buf1, arg0, 0, 0);
    func_002ED0B0(arg0, buf0, buf1, 0);
    func_002F3A88(buf1, arg2, arg3);
    func_002EDC38(buf0, buf1, arg1);
    t = func_002FABA0(buf0);
    v = *arg2 + t;
    *arg2 = v;
    return (s32)v;
}
