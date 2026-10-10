#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E60_arg0 {
    char pad0[0x85];
    u8 unk85;
};

u8 func_00565E60(struct func_00565E60_arg0 *arg0) {
    return arg0->unk85;
}
