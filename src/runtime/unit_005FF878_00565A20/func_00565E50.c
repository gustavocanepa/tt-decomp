#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565E50_arg0 {
    char pad0[0x7E];
    u8 unk7E;
};

u8 func_00565E50(struct func_00565E50_arg0 *arg0) {
    return arg0->unk7E;
}
