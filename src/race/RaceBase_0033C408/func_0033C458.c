#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002FC298(s32);                             /* extern */

struct func_0033C458_arg0_unk6C {
    char pad0[0x60];
    void *unk60;
};
struct func_0033C458_arg0 {
    char pad0[0x6C];
    struct func_0033C458_arg0_unk6C *unk6C;
    char pad70[0xD1C];
    u32 unkD8C;
    char padD90[0x50];
    s32 unkDE0;
};

void func_0033C458(struct func_0033C458_arg0 *arg0) {
    if ((u32) arg0->unkD8C < 2U) {
        arg0->unkDE0 = func_002FC298(M2C_FIELD(M2C_FIELD(*M2C_FIELD(arg0->unk6C->unk60, void ***, 8), void **, 0x18), s32 *, 4));
    }
}
