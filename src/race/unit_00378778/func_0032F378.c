#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0032E988(s32, s32);                    /* extern */
s32 func_00553F68(s32, void *);                 /* extern */

struct func_0032F378_arg0 {
    char pad0[0x3B00];
    s32 unk3B00;
    char pad3B04[0x20];
    s32 unk3B24;
    s32 unk3B28;
};
struct func_0032F378_arg1 {
    char pad0[0x3B00];
    s32 unk3B00;
    char pad3B04[0x20];
    s32 unk3B24;
    s32 unk3B28;
};

void *func_0032F378(void *arg0, void *arg1) {
    s32 var_s0;
    s32 var_s2;

    var_s0 = 0;
    var_s2 = 1;
    do {
        var_s2 -= 1;
        func_0032E988(arg0 + var_s0, arg1 + var_s0);
        var_s0 += 0x1D80;
    } while (var_s2 >= 0);
    ((struct func_0032F378_arg0 *)arg0)->unk3B00 = (s32) ((struct func_0032F378_arg1 *)arg1)->unk3B00;
    func_00553F68(arg0 + 0x3B04, arg1 + 0x3B04);
    ((struct func_0032F378_arg0 *)arg0)->unk3B24 = (s32) ((struct func_0032F378_arg1 *)arg1)->unk3B24;
    ((struct func_0032F378_arg0 *)arg0)->unk3B28 = (s32) ((struct func_0032F378_arg1 *)arg1)->unk3B28;
    return arg0;
}
