#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0026FEC0_temp_v0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
};

struct func_0026FEC0_arg0 {
    char pad0[0x5C];
    f32 unk5C;
    char pad60[0x8];
    s32 unk68;
    char pad6C[0x810];
    s32 unk87C;
};

void func_0026FEC0(void *arg0, f32 fparg0) {
    struct func_0026FEC0_temp_v0 *temp_v0;

    temp_v0 = arg0 + 0x68;
    ((struct func_0026FEC0_arg0 *)arg0)->unk87C = 1;
    ((struct func_0026FEC0_arg0 *)arg0)->unk5C = fparg0;
    ((struct func_0026FEC0_arg0 *)arg0)->unk68 = 0;
    temp_v0->unk4 = 0;
    temp_v0->unk8 = 0;
}
