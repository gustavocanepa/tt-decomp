#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001A1E48_arg0 {
    s8 unk0;
    char pad1[0x1F];
    s32 unk20;
    s32 unk24;
    s32 unk28;
};

void func_001A1E48(struct func_001A1E48_arg0 *arg0) {
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk0 = 0;
}
