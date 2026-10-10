#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00376CC8_arg0 {
    char pad0[0x96C];
    u8 unk96C;
};

u8 func_00376CC8(struct func_00376CC8_arg0 *arg0) {
    return arg0->unk96C;
}
