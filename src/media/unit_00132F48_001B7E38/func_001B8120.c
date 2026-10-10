#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DBFD8(void *, void *);              /* extern */
s32 func_00202968();                            /* extern */

extern char D_005AE9C8[];
extern char D_005AED80[];
extern char D_005AEDB0[];
struct func_001B8120_temp_s1 {
    char pad0[0x18];
    s32 unk18;
};

struct func_001B8120_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
    char pad30[0xA0];
    s32 unkD0;
};

s32 func_001B8120(void *arg0) {
    struct func_001B8120_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0xB4;
    func_00202968();
    ((struct func_001B8120_arg0 *)arg0)->unk4 = (s32)D_005AE9C8;
    ((struct func_001B8120_arg0 *)arg0)->unk2C = (s32)D_005AED80;
    func_001DBFD8(temp_s1, arg0);
    temp_s1->unk18 = (s32)D_005AEDB0;
    ((struct func_001B8120_arg0 *)arg0)->unkD0 = 0;
}
