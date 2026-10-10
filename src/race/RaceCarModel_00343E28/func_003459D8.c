#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003700A0(void *);                      /* extern */

struct func_003459D8_arg0 {
    char pad0[0x3550];
    s32 unk3550;
    s32 unk3554;
};

s32 func_003459D8(void *arg0) {
    if (((struct func_003459D8_arg0 *)arg0)->unk3550 != 0) {
        func_003700A0(arg0 + 0x620);
    }
    if (((struct func_003459D8_arg0 *)arg0)->unk3554 != 0) {
        func_003700A0(arg0 + 0x1DB0);
    }
}
