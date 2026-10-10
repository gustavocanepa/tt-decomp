#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00460F68();                            /* extern */

struct func_0045F710_arg0 {
    char pad0[0x98];
    s32 unk98;
};

s32 func_0045F710(struct func_0045F710_arg0 *arg0) {
    if (arg0->unk98 != 0) {
        arg0->unk98 = 0;
        func_00460F68();
    }
}
