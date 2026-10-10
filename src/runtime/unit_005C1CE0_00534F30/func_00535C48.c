#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535C48_arg0 {
    char pad0[0x78];
    f32 unk78;
};

f32 func_00535C48(struct func_00535C48_arg0 *arg0) {
    return arg0->unk78;
}
