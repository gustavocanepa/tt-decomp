#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004FA830(s32);                         /* extern */

extern char D_00598410[];
struct func_004CDAE0_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

void func_004CDAE0(struct func_004CDAE0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk1C;
    if (temp_v0 != -1) {
        func_004FA830(temp_v0);
        arg0->unk1C = -1;
        *(s32 *)D_00598410 = 0;
    }
    func_004FA830(arg0->unk20);
}
