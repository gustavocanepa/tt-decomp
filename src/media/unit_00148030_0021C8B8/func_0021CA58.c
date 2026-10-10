#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0021CA58_arg0 {
    char pad0[0x78];
    f32 unk78;
};

f32 func_0021CA58(struct func_0021CA58_arg0 *arg0) {
    return 0x1.0000000000000p+0f / arg0->unk78;
}
