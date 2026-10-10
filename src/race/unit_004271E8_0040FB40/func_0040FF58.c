#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0040FF58_arg0 {
    char pad0[0x15];
    u8 unk15;
};

u8 func_0040FF58(struct func_0040FF58_arg0 *arg0) {
    return arg0->unk15;
}
