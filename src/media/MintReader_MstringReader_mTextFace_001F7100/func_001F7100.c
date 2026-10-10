#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_00586EF4[];
struct func_001F7100_arg0 {
    char pad0[0x5C];
    f32 unk5C;
    f32 unk60;
};
struct func_001F7100_temp_v1 {
    char pad0[0x54];
    f32 unk54;
    f32 unk58;
};

void func_001F7100(struct func_001F7100_arg0 *arg0) {
    struct func_001F7100_temp_v1 *temp_v1;

    temp_v1 = *(void **)D_00586EF4;
    arg0->unk5C = (f32) temp_v1->unk54;
    arg0->unk60 = (f32) temp_v1->unk58;
}
