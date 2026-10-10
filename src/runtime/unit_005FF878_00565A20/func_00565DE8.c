#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565DE8_arg0 {
    char pad0[0x3A];
    s16 unk3A;
};

s16 func_00565DE8(struct func_00565DE8_arg0 *arg0) {
    return arg0->unk3A;
}
