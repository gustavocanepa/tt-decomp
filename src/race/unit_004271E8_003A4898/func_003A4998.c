#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003A4998_arg0 {
    char pad0[0x2];
    s16 unk2;
};

s16 func_003A4998(struct func_003A4998_arg0 *arg0) {
    return arg0->unk2;
}
