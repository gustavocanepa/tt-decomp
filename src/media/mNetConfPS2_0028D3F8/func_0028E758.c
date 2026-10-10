#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B5610();                            /* extern */
void *GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *); /* extern */

extern char D_00547118[];
extern char D_0054D6E8[];
struct func_0028E758_temp_v0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};
struct func_0028E758_arg0 {
    char pad0[0xE0];
    s32 unkE0;
    s32 unkE4;
};
struct func_0028E758_var_v1 {
    char pad0[0xE0];
    s32 unkE0;
    s32 unkE4;
};

struct func_0028E758_arg1 {
    char pad0[0x4];
    void *unk4;
};

void func_0028E758(struct func_0028E758_arg0 *arg0, void *arg1) {
    struct func_0028E758_temp_v0 *temp_v0;
    struct func_0028E758_var_v1 *var_v1;

    func_001B5610();
    var_v1 = NULL;
    if (arg1 != NULL) {
        temp_v0 = ((struct func_0028E758_arg1 *)arg1)->unk4;
        var_v1 = GT4MC__FileGT4GameData__loadInstance(temp_v0->unk4, (s32)D_00547118, 0, arg1 + temp_v0->unk0, (s32)D_0054D6E8, arg1);
    }
    if (var_v1 != NULL) {
        arg0->unkE0 = (s32) var_v1->unkE0;
        arg0->unkE4 = (s32) var_v1->unkE4;
    }
}
