#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005CE270[];
struct NormalCarGeometry__structor_2_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

s32 NormalCarGeometry__structor_2(struct NormalCarGeometry__structor_2_arg0 *arg0) {
    arg0->unk8 = 0;
    arg0->unk0 = (s32)D_005CE270;
}
