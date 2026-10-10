#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0055AC60_arg0_unk60 {
    char pad0[0x8];
    s32 unk8;
};
struct func_0055AC60_arg0 {
    char pad0[0x60];
    struct func_0055AC60_arg0_unk60 *unk60;
};

s32 func_0055AC60(struct func_0055AC60_arg0 *arg0, s32 arg1) {
    return *(s32 *)((arg1 * 4) + arg0->unk60->unk8) + 0x20;
}
