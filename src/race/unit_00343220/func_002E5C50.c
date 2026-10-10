#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5C50_arg0 {
    char pad0[0x718];
    u8 unk718;
};

u8 func_002E5C50(struct func_002E5C50_arg0 *arg0) {
    return arg0->unk718;
}
