#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005619D8_arg0 {
    char pad0[0x2A];
    u8 unk2A;
};

u8 func_005619D8(struct func_005619D8_arg0 *arg0) {
    return arg0->unk2A;
}
