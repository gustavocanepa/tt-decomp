#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

typedef struct { s32 p0; s32 x; u8 pad[0x170]; } E;
s32 func_003C8650(void *, s32);
struct func_003C8888_arg0 {
    char pad0[0xC];
    E *unkC;
};

void func_003C8888(struct func_003C8888_arg0 *arg0, s32 arg1, s32 arg2) {
    if (func_003C8650(arg0, arg1) != 0) {
        E *p = arg0->unkC; p += arg1; p->x = arg2;
    }
}
