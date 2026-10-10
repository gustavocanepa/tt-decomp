#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002EE7D8_arg0 {
    char pad0[0x58C];
    f32 unk58C;
};

f32 func_002EE7D8(struct func_002EE7D8_arg0 *arg0) {
    return arg0->unk58C;
}
