#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct hBuiltinAttribute__virtual_08_arg0 {
    char pad0[0xC];
    s32 (*unkC)(s32, s32, s32, s32);
};

void hBuiltinAttribute__virtual_08(struct hBuiltinAttribute__virtual_08_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unkC(arg1, arg2, 0, 0);
}
