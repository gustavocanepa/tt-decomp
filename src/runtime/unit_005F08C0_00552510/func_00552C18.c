#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00552C18_arg0 {
    char pad0[0xD8];
    f32 unkD8;
};

f32 func_00552C18(struct func_00552C18_arg0 *arg0) {
    return arg0->unkD8;
}
