#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B08B8();                            /* extern */

extern char D_005DAE78[];
struct func_004B09F8_arg0 {
    char pad0[0x28];
    s32 unk28;
    char pad2C[0x4];
    s32 unk30;
};

s32 func_004B09F8(void *arg0) {
    func_004B08B8();
    ((struct func_004B09F8_arg0 *)arg0)->unk28 = (s32) (arg0 + 0x38);
    ((struct func_004B09F8_arg0 *)arg0)->unk30 = (s32)D_005DAE78;
}
