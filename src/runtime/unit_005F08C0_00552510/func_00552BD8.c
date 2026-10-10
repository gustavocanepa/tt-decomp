#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552BD8_arg0 {
    char pad0[0xAC];
    f32 unkAC;
};

f32 func_00552BD8(struct func_00552BD8_arg0 *arg0) {
    return arg0->unkAC;
}
