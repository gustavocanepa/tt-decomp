#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0024D148();                            /* extern */
void *GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *); /* extern */

extern char D_005443D8[];
extern char D_0054D6E8[];
struct func_002728F8_temp_v0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};
struct func_002728F8_arg0 {
    char pad0[0x8C];
    f32 unk8C;
    f32 unk90;
};
struct func_002728F8_var_v0 {
    char pad0[0x8C];
    f32 unk8C;
    f32 unk90;
};

struct func_002728F8_arg1 {
    char pad0[0x4];
    void *unk4;
};

void func_002728F8(struct func_002728F8_arg0 *arg0, void *arg1) {
    struct func_002728F8_temp_v0 *temp_v0;
    struct func_002728F8_var_v0 *var_v0;

    func_0024D148();
    var_v0 = NULL;
    if (arg1 != NULL) {
        temp_v0 = ((struct func_002728F8_arg1 *)arg1)->unk4;
        var_v0 = GT4MC__FileGT4GameData__loadInstance(temp_v0->unk4, (s32)D_005443D8, 0, arg1 + temp_v0->unk0, (s32)D_0054D6E8, arg1);
    }
    if (var_v0 != NULL) {
        arg0->unk8C = (f32) var_v0->unk8C;
        arg0->unk90 = (f32) var_v0->unk90;
    }
}
