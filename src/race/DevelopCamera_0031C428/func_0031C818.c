#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031C818_arg0 {
    char pad0[0xCBD];
    u8 unkCBD;
};

u8 func_0031C818(struct func_0031C818_arg0 *arg0) {
    return arg0->unkCBD;
}
