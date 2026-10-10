#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_002A7590(s32, void *);                 /* extern */
s32 func_002B1AB8(void *, s32 *);                   /* extern */
s32 hThread__execute(void *, s32);                     /* extern */
s32 func_002BAD00(void *, s32, s32, s32, s32);  /* extern */

struct func_002BB2B8_temp_v1 {
    char pad0[0x14];
    s32 unk14;
};

struct func_002BB2B8_arg1 {
    char pad0[0x2C];
    void *unk2C;
    char pad30[0x4];
    s32 unk34;
    char pad38[0xC];
    s32 unk44;
    s32 unk48;
};

s32 hThread__execCode(s32 arg0, void *arg1, s32 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s5;
    struct func_002BB2B8_temp_v1 *temp_v1;

    temp_s5 = func_002B1AB8(arg1, arg2);
    func_002BAD00(arg1, *arg2 + 0x10, arg4, arg5, arg3);
    do {

    } while (hThread__execute(arg1, temp_s5) == 2);
    if (((struct func_002BB2B8_arg1 *)arg1)->unk34 == 1) {
        temp_v1 = ((struct func_002BB2B8_arg1 *)arg1)->unk2C;
        temp_v1->unk14 = (s32) (temp_v1->unk14 - 1);
    }
    ((struct func_002BB2B8_arg1 *)arg1)->unk34 = 3;
    ((struct func_002BB2B8_arg1 *)arg1)->unk48 = (s32) ((struct func_002BB2B8_arg1 *)arg1)->unk44;
    func_002A7590(arg0, arg1 + 0x30);
    return arg0;
}
