#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F9A78_arg0 {
    char pad0[0x7E4];
    f32 unk7E4;
};

f32 func_002F9A78(struct func_002F9A78_arg0 *arg0) {
    return arg0->unk7E4;
}
