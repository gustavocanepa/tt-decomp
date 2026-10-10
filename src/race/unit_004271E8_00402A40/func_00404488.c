#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00404488_arg0 {
    char pad0[0x10];
    s8 unk10;
};

s8 func_00404488(struct func_00404488_arg0 *arg0) {
    return arg0->unk10;
}
