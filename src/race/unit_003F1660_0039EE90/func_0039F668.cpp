#include "types.h"

extern "C" f32 func_0039F5A8(char *arg0, s32 arg1);
extern "C" void func_002E79D8(void *arg0);

extern "C" void func_0039F668(char *arg0) {
    char *q = *(char **)(arg0 + 0x10);
    if (*(u8 *)(q + 0x10C2) != 0) {
        s32 i = 0;
        f32 acc = 0.0f;
        s32 one = 1;
        char *p = arg0 + 0x164;
        do {
            f32 r = func_0039F5A8(arg0, i);
            f32 v = *(f32 *)(p + 0x94);
            s32 t = i >> 1;
            i += 1;
            v = v - r;
            *(f32 *)(p + 0x94) = v;
            p += 0xF4;
            acc = acc - r * ((f32 *)(q + 0x20))[one - t];
        } while (i < 4);
        char *w = arg0 + 0x104;
        *(f32 *)(w + 8) = *(f32 *)(w + 8) + acc * 0.5f;
        return func_002E79D8(arg0);
    }
}
