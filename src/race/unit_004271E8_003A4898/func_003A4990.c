#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A4990_arg0 {
    char pad0[0x2];
    s16 unk2;
};

void func_003A4990(struct func_003A4990_arg0 *arg0, s16 arg1) {
    arg0->unk2 = arg1;
}
