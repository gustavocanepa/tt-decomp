#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0056A050_arg0 {
    char pad0[0x4];
    void *unk4;
};
struct func_0056A050_temp_v1 {
    char pad0[0x2];
    s16 unk2;
    s16 unk4;
};

s32 func_0056A050(struct func_0056A050_arg0 *arg0, s32 arg1) {
    s32 var_a0;
    struct func_0056A050_temp_v1 *temp_v1;

    temp_v1 = arg0->unk4;
    var_a0 = 0;
    if (arg1 >= temp_v1->unk2) {
        var_a0 = arg1 < temp_v1->unk4;
    }
    return var_a0;
}
