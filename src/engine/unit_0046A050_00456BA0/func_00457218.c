#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0045A168(void *, void *);                  /* extern */
s32 func_0045BFE8(s32, void *, s32);                /* extern */

struct func_00457218_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char padC[0x8D0];
    s32 unk8DC;
};

s32 func_00457218(void *arg0) {
    if (((struct func_00457218_arg0 *)arg0)->unk0 == 0) {
        ((struct func_00457218_arg0 *)arg0)->unk8 = 1;
        ((struct func_00457218_arg0 *)arg0)->unk4 = 3;
        return 0;
    }
    if (func_0045BFE8(arg0 + 0xC, arg0 + 0x8C4, ((struct func_00457218_arg0 *)arg0)->unk8DC) == 0) {
        func_00456D10(arg0);
        return 0;
    }
    if (func_0045A168(arg0 + 0x85C, arg0 + 0x8E0) == 0) {
        func_00456D68(arg0);
        return 0;
    }
    return 1;
}
