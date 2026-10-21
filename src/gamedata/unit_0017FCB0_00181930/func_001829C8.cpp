#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
void func_004A58A0(s32);                        /* extern, defined as void func_004A58A0(void) */

struct func_001829C8_arg0 {
    char pad0[0xC8];
    volatile s32 unkB4;
    volatile s32 unkB8;
    volatile s32 unkBC;
    volatile s32 unkC0;
};

s32 func_001829C8(void *arg0, s32 arg1, s32 arg2) {
    struct func_001829C8_arg0 *s = (struct func_001829C8_arg0 *)arg0;
    s32 t;

    s->unkBC = 0;
    s->unkB4 = arg1;
    t = s->unkBC;
    s->unkB8 = arg2;
    if (t == 0) {
        do {
            func_004A58A0(0x3E80);
        } while (s->unkBC == 0);
    }
    return s->unkC0;
}

}
