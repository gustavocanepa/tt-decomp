#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *); /* extern */

extern char D_0052FE98[];
extern char D_00536BC0[];
struct func_001BEBA0_arg0 {
    char pad0[0x4C];
    void *unk4C;
    char pad50[0x28];
    s32 unk78;
};
struct func_001BEBA0_temp_v0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};

struct func_001BEBA0_arg1 {
    char pad0[0x4];
    void *unk4;
};

void func_001BEBA0(struct func_001BEBA0_arg0 *arg0, void *arg1) {
    s32 var_v0;
    struct func_001BEBA0_temp_v0 *temp_v0;

    arg0->unk4C = arg1;
    var_v0 = 0;
    if (arg1 != NULL) {
        temp_v0 = ((struct func_001BEBA0_arg1 *)arg1)->unk4;
        var_v0 = GT4MC__FileGT4GameData__loadInstance(temp_v0->unk4, (s32)D_00536BC0, 0, arg1 + temp_v0->unk0, (s32)D_0052FE98, arg1);
    }
    arg0->unk78 = var_v0;
}
