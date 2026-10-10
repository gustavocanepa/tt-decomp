#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005528D8_arg0 {
    char pad0[0x20A48];
    f32 unk20A48;
};

f32 func_005528D8(struct func_005528D8_arg0 *arg0) {
    return arg0->unk20A48;
}
