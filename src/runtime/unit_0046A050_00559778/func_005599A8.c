#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005599A8_arg0 {
    char pad0[0x117C];
    s16 unk117C;
};

void func_005599A8(struct func_005599A8_arg0 *arg0, s16 arg1) {
    arg0->unk117C = arg1;
}
