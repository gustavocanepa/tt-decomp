#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005DB7C0[];
struct func_00577AF8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_00577AF8(struct func_00577AF8_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = (s32)D_005DB7C0;
}
