#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00407728(void *, s32);                     /* extern */
u8 func_0040CDD0(void *, s32, u8, u8);            /* extern */

struct func_00407F48_arg0 {
    char pad0[0x4D8];
    s32 unk4D8;
};
struct func_00407F48_temp_s0 {
    char pad0[0xE8];
    s64 unkE8;
    char padF0[0x66];
    u8 unk156;
};
struct func_00407F48_arg2 {
    char pad0[0x11E];
    u8 unk11E;
    char pad11F[0x2];
    u8 unk121;
};

void func_00407F48(void *arg0, s64 arg1, struct func_00407F48_arg2 *arg2) {
    struct func_00407F48_temp_s0 *temp_s0;

    temp_s0 = arg0 + (((struct func_00407F48_arg0 *)arg0)->unk4D8 * 0x190) + 8;
    ((struct func_00407F48_temp_s0 *)temp_s0)->unkE8 = arg1;
    func_00407728(arg0, arg2);
    temp_s0->unk156 = func_0040CDD0(temp_s0, 1, arg2->unk121, arg2->unk11E);
}
