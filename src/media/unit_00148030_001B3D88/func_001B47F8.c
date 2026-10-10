#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001B47F8_arg0 {
    char pad0[0xD4];
    s16 unkD4;
    s16 unkD6;
    s16 unkD8;
    s16 unkDA;
};

void func_001B47F8(struct func_001B47F8_arg0 *arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    if (arg1 != NULL) {
        *arg1 = (s32) arg0->unkD4;
    }
    if (arg2 != NULL) {
        *arg2 = (s32) arg0->unkD6;
    }
    if (arg3 != NULL) {
        *arg3 = (s32) arg0->unkD8;
    }
    if (arg4 != NULL) {
        *arg4 = (s32) arg0->unkDA;
    }
}
