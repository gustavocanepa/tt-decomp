#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056EBA0_arg0 {
    char pad0[0x28];
    s64 unk28;
};

void func_0056EBA0(struct func_0056EBA0_arg0 *arg0, s64 arg1) {
    arg0->unk28 = arg1;
}
