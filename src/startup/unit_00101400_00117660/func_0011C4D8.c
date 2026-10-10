#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AEAF8(void *);                      /* extern */

struct func_0011C4D8_arg0 {
    char pad0[0x2A4];
    s32 unk2A4;
};

s32 func_0011C4D8(void *arg0) {
    if (((struct func_0011C4D8_arg0 *)arg0)->unk2A4 != 0) {
        ((struct func_0011C4D8_arg0 *)arg0)->unk2A4 = 0;
        func_004AEAF8(arg0 + 0x18);
    }
}
