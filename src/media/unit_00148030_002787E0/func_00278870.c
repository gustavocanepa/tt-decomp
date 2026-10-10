#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00278870_arg0 {
    char pad0[0xDC];
    f32 unkDC;
};

f32 func_00278870(struct func_00278870_arg0 *arg0) {
    return arg0->unkDC;
}
