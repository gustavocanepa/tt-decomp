#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004C8F58_arg0 {
    char pad0[0x2FEC];
    s32 unk2FEC;
};

void func_004C8F58(struct func_004C8F58_arg0 *arg0, s32 arg1) {
    arg0->unk2FEC = arg1;
}
