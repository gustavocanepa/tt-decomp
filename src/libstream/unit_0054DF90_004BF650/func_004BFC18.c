#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0(void *);                      /* extern */
s32 func_004BFAD8(s32);                         /* extern */
s32 func_004C9F20();                            /* extern */
s32 func_005738E8(s32, void *);                 /* extern */

extern char D_005DB158[];
struct func_004BFC18_arg0 {
    s32 unk0;
    char pad4[0x3C];
    s32 unk40;
    char pad44[0x3C];
    s32 unk80;
    char pad84[0x10];
    s32 unk94;
};

void func_004BFC18(void *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0 + 4;
    func_004C9F20();
    ((struct func_004BFC18_arg0 *)arg0)->unk0 = (s32)D_005DB158;
    func_005738E8(temp_s1, arg0);
    func_004AE9C0(arg0 + 0x10);
    ((struct func_004BFC18_arg0 *)arg0)->unk40 = arg1;
    ((struct func_004BFC18_arg0 *)arg0)->unk80 = 0;
    ((struct func_004BFC18_arg0 *)arg0)->unk94 = 0;
    func_004BFAD8(temp_s1);
}
