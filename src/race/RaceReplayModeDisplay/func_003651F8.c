#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(s32);                         /* extern */

extern char D_005F5B68[];
extern char D_005F5B78[];
extern char D_005F5B88[];
extern char D_005F5BE0[];
extern char D_005F5BF0[];
extern char D_005F5C00[];
extern char D_005F5C18[];
struct func_003651F8_arg0 {
    char pad0[0x10];
    s32 unk10;
    char pad14[0xF8];
    s32 unk10C;
    s32 unk110;
    s32 unk114;
    char pad118[0x4];
    s32 unk11C;
    s32 unk120;
    s32 unk124;
};

void func_003651F8(struct func_003651F8_arg0 *arg0) {
    arg0->unk10 = func_00357310((s32)D_005F5BE0);
    arg0->unk10C = func_00357310((s32)D_005F5BF0);
    arg0->unk110 = func_00357310((s32)D_005F5C00);
    arg0->unk114 = func_00357310((s32)D_005F5C18);
    arg0->unk11C = func_00357310((s32)D_005F5B68);
    arg0->unk120 = func_00357310((s32)D_005F5B78);
    arg0->unk124 = func_00357310((s32)D_005F5B88);
}
