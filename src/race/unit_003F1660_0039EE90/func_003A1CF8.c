#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F0218();                            /* extern */

extern char D_005D5FF0[];
struct func_003A1CF8_arg0 {
    char pad0[0x241CC];
    s32 unk241CC;
};

void func_003A1CF8(struct func_003A1CF8_arg0 *arg0) {
    func_002F0218();
    arg0->unk241CC = (s32)D_005D5FF0;
}
