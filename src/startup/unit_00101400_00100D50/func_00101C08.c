#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00101C08_arg0 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
};

void func_00101C08(struct func_00101C08_arg0 *arg0) {
    arg0->unk4 = 0;
    arg0->unk2 = 0;
    arg0->unk0 = 0;
    arg0->unkA = 0;
    arg0->unk8 = 0;
    arg0->unk6 = 0;
}
