#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct CompatibleModel__virtual_04_arg0 {
    char pad0[0x54];
    s32 (*unk54)(s32);
    s32 unk58;
};

void CompatibleModel__virtual_04(struct CompatibleModel__virtual_04_arg0 *arg0) {
    arg0->unk54(arg0->unk58);
}
