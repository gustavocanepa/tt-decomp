#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00538B50(void *);                          /* extern */

struct func_0022D218_temp_s0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_0022D218(s32 arg0) {
    struct func_0022D218_temp_s0 *temp_s0;

    temp_s0 = arg0 + 0x20;
    return func_00538B50(temp_s0) != temp_s0->unk4;
}
