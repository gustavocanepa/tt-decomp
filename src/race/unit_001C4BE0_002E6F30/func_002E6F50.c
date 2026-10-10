#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6F50_arg0 {
    char pad0[0x58B];
    s8 unk58B;
};

s32 func_002E6F50(struct func_002E6F50_arg0 *arg0) {
    arg0->unk58B = 8;
    return 1;
}
