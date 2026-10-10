#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00357310(s32);                         /* extern */

extern char D_005F5B38[];
extern char D_005F5B48[];
extern char D_005F5B58[];
extern char D_005F5B68[];
extern char D_005F5B78[];
extern char D_005F5B88[];
struct func_003644F0_arg0 {
    char pad0[0x114];
    s32 unk114;
    s32 unk118;
    s32 unk11C;
    char pad120[0x4];
    s32 unk124;
    s32 unk128;
    s32 unk12C;
};

void func_003644F0(struct func_003644F0_arg0 *arg0) {
    arg0->unk114 = func_00357310((s32)D_005F5B38);
    arg0->unk118 = func_00357310((s32)D_005F5B48);
    arg0->unk11C = func_00357310((s32)D_005F5B58);
    arg0->unk124 = func_00357310((s32)D_005F5B68);
    arg0->unk128 = func_00357310((s32)D_005F5B78);
    arg0->unk12C = func_00357310((s32)D_005F5B88);
}
