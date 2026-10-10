#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00119108(s32, s32, void *);            /* extern */
s32 func_0020B378();                            /* extern */

struct mLoggerFace__virtual_67_arg0 {
    char pad0[0xB4];
    s32 unkB4;
    s32 unkB8;
};

s32 mLoggerFace__virtual_67(struct mLoggerFace__virtual_67_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    func_0020B378();
    temp_v0 = arg0->unkB8;
    arg0->unkB4 = arg1;
    if (temp_v0 != 0) {
        func_00119108(temp_v0, arg1, arg0);
    }
}
