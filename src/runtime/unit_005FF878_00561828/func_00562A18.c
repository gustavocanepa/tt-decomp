#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562A18_arg0 {
    char pad0[0x1138];
    s32 unk1138;
};

void func_00562A18(struct func_00562A18_arg0 *arg0, s32 arg1) {
    arg0->unk1138 = arg1;
}
