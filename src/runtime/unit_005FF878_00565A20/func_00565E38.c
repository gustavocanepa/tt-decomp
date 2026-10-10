#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E38_arg0 {
    char pad0[0x75];
    u8 unk75;
};

u8 func_00565E38(struct func_00565E38_arg0 *arg0) {
    return arg0->unk75;
}
