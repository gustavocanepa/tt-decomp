#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002EA5F8_arg0 {
    char pad0[0x567];
    s8 unk567;
};

void func_002EA5F8(struct func_002EA5F8_arg0 *arg0, s8 arg1) {
    arg0->unk567 = arg1;
}
