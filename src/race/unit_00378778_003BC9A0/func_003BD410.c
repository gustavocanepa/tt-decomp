#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003BD410_arg0 {
    char pad0[0x31];
    u8 unk31;
};

u8 func_003BD410(struct func_003BD410_arg0 *arg0) {
    return arg0->unk31;
}
