#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct HModuleFrame__virtual_02_arg1 {
    char pad0[0x20];
    s32 unk20;
};
struct HModuleFrame__virtual_02_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void HModuleFrame__end(struct HModuleFrame__virtual_02_arg0 *arg0, struct HModuleFrame__virtual_02_arg1 *arg1) {
    arg1->unk20 = (s32) arg0->unk4;
}
