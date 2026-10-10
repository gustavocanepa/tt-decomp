#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */

extern char D_005D8C08[];
struct func_003FA4F8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_003FA4F8(struct func_003FA4F8_arg0 *arg0) {
    func_00400D68();
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_005D8C08;
}
