#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562AB8_arg0 {
    char pad0[0x1144];
    s32 unk1144;
};

void func_00562AB8(struct func_00562AB8_arg0 *arg0, s32 arg1) {
    arg0->unk1144 = arg1;
}
