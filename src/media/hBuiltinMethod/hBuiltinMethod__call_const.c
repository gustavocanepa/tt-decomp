#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct hBuiltinMethod__virtual_15_arg0 {
    char pad0[0xC];
    s32 (*unkC)(s32, s32, s32, s32);
};

void hBuiltinMethod__call_const(struct hBuiltinMethod__virtual_15_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->unkC(arg1, arg2, arg3, arg4);
}
