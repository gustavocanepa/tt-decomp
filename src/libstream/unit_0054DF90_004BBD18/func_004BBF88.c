#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004BC018(void *, void *, void *, void *, void *); /* extern */
s32 func_004FA6B0(s32, s32);                        /* extern */
s32 func_004FA710();                                /* extern */

struct func_004BBF88_arg0 {
    char pad0[0x1A8];
    s32 unk1A8;
    char pad1AC[0x248];
    s32 unk3F4;
};

s32 func_004BBF88(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;
    s32 var_s3;

    var_s3 = 1;
    if (((struct func_004BBF88_arg0 *)arg0)->unk1A8 == 0) {
        temp_v0 = func_004FA710();
        temp_s1 = func_004FA6B0(temp_v0, ((struct func_004BBF88_arg0 *)arg0)->unk3F4);
        var_s3 = func_004BC018(arg0, arg0 + 0x1AC, arg0 + 0x84, arg0 + 0x80, arg0);
        func_004FA6B0(temp_v0, temp_s1);
    }
    return var_s3;
}
