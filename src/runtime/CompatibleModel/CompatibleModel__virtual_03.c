#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct CompatibleModel__virtual_03_arg0 {
    char pad0[0x4C];
    s32 (*unk4C)(s32);
    s32 unk50;
};

void CompatibleModel__virtual_03(struct CompatibleModel__virtual_03_arg0 *arg0) {
    arg0->unk4C(arg0->unk50);
}
