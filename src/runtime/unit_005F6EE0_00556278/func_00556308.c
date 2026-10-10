#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00556308_arg0 {
    char pad0[0xCC];
    f32 unkCC;
};

f32 func_00556308(struct func_00556308_arg0 *arg0) {
    return arg0->unkCC;
}
