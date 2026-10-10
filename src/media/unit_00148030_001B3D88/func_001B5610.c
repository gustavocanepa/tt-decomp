#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B9AF0();                            /* extern */
void *GT4MC__FileGT4GameData__loadInstance(s32, s32, s32, void *, s32, void *); /* extern */

extern char D_00522F68[];
extern char D_0054D6E8[];
struct func_001B5610_temp_v0 {
    s16 unk0;
    char pad2[0x2];
    s32 unk4;
};
struct func_001B5610_arg0 {
    char pad0[0xD4];
    u16 unkD4;
    u16 unkD6;
    u16 unkD8;
    u16 unkDA;
};
struct func_001B5610_var_a0 {
    char pad0[0xD4];
    u16 unkD4;
    u16 unkD6;
    u16 unkD8;
    u16 unkDA;
};

struct func_001B5610_arg1 {
    char pad0[0x4];
    void *unk4;
};

void func_001B5610(struct func_001B5610_arg0 *arg0, void *arg1) {
    struct func_001B5610_temp_v0 *temp_v0;
    struct func_001B5610_var_a0 *var_a0;

    func_001B9AF0();
    var_a0 = NULL;
    if (arg1 != NULL) {
        temp_v0 = ((struct func_001B5610_arg1 *)arg1)->unk4;
        var_a0 = GT4MC__FileGT4GameData__loadInstance(temp_v0->unk4, (s32)D_00522F68, 0, arg1 + temp_v0->unk0, (s32)D_0054D6E8, arg1);
    }
    if (var_a0 != NULL) {
        arg0->unkD4 = (u16) var_a0->unkD4;
        arg0->unkD6 = (u16) var_a0->unkD6;
        arg0->unkD8 = (u16) var_a0->unkD8;
        arg0->unkDA = (u16) var_a0->unkDA;
    }
}
