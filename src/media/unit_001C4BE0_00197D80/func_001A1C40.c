#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004B8F30(s32);                             /* extern */
s32 func_004BA058(s32);                             /* extern */

struct func_001A1C40_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_001A1C40(struct func_001A1C40_arg0 *arg0) {
    if (func_004B8F30(arg0->unk4) != 0) {
        return 0;
    }
    return func_004BA058(arg0->unk4);
}
