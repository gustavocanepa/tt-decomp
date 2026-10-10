/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_002CF7F8_arg0_unk6C {
    char pad0[0x80];
    void *unk80;
};
struct func_002CF7F8_arg0 {
    char pad0[0x6C];
    struct func_002CF7F8_arg0_unk6C *unk6C;
    char pad70[0xCF74];
    s32 unkCFE4;
};

void func_002CF7F8(struct func_002CF7F8_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkCFE4 = arg2;
    M2C_FIELD(arg0->unk6C->unk80, s32 *, 0xBC) = arg1;
}
