#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001CDA38_arg0 {
    char pad0[0x24];
    f32 unk24;
};

f32 func_001CDA38(struct func_001CDA38_arg0 *arg0) {
    return arg0->unk24;
}
