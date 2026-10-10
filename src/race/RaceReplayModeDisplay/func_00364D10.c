#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(s32);                         /* extern */

extern char D_005F5B68[];
extern char D_005F5B78[];
extern char D_005F5B88[];
extern char D_005F5B90[];
extern char D_005F5BA0[];
extern char D_005F5BB0[];
struct func_00364D10_arg0 {
    char pad0[0x110];
    s32 unk110;
    s32 unk114;
    s32 unk118;
    char pad11C[0x8];
    s32 unk124;
    s32 unk128;
    s32 unk12C;
};

void func_00364D10(struct func_00364D10_arg0 *arg0) {
    arg0->unk110 = func_00357310((s32)D_005F5B90);
    arg0->unk114 = func_00357310((s32)D_005F5BA0);
    arg0->unk118 = func_00357310((s32)D_005F5BB0);
    arg0->unk124 = func_00357310((s32)D_005F5B68);
    arg0->unk128 = func_00357310((s32)D_005F5B78);
    arg0->unk12C = func_00357310((s32)D_005F5B88);
}
