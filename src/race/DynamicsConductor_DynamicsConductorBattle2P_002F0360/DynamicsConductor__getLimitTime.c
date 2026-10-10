#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F0488_arg0 {
    char pad0[0x23918];
    u16 unk23918;
};

s32 DynamicsConductor__getLimitTime(struct func_002F0488_arg0 *arg0) {
    return arg0->unk23918 * 0xEA60;
}
