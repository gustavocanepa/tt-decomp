#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004BB4B8();                            /* extern */
s32 func_004BDC28(s32);                         /* extern */
s32 func_004CDAE0(s32);                         /* extern */
s32 func_004FA630(s32);                         /* extern */
s32 func_004FA670(s32);                         /* extern */

extern char D_00598424[];
struct func_004BD758_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
};

void func_004BD758(struct func_004BD758_arg0 *arg0) {
    s32 temp_s1;

    func_004CDAE0(arg0->unkC);
    func_004BDC28(arg0->unk8);
    func_004BB4B8();
    temp_s1 = arg0->unk0;
    func_004FA670(temp_s1);
    func_004FA630(temp_s1);
    *(s32 *)D_00598424 = 0;
}
