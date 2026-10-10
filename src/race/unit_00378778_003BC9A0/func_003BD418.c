#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003BD418_arg0 {
    char pad0[0x32];
    u8 unk32;
};

u8 func_003BD418(struct func_003BD418_arg0 *arg0) {
    return arg0->unk32;
}
