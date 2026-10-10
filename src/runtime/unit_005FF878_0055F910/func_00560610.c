#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00560610_arg0 {
    char pad0[0x8FC];
    s32 unk8FC;
};

void func_00560610(struct func_00560610_arg0 *arg0, s32 arg1) {
    arg0->unk8FC = arg1;
}
