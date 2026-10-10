#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00375408(void *);                      /* extern */
s32 func_0041AD58(s32);                         /* extern */

struct func_00345988_arg0 {
    char pad0[0x3550];
    s32 unk3550;
    s32 unk3554;
};

s32 func_00345988(void *arg0) {
    func_0041AD58(arg0 + 0x18);
    if (((struct func_00345988_arg0 *)arg0)->unk3550 != 0) {
        func_00375408(arg0 + 0x620);
    }
    if (((struct func_00345988_arg0 *)arg0)->unk3554 != 0) {
        func_00375408(arg0 + 0x1DB0);
    }
}
