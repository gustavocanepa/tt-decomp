#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005529E8_arg0 {
    char pad0[0x20A24];
    u8 unk20A24;
};

u8 func_005529E8(struct func_005529E8_arg0 *arg0) {
    return arg0->unk20A24;
}
