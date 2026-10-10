#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */

extern char D_005D8C88[];
struct func_003FC340_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_003FC340(struct func_003FC340_arg0 *arg0) {
    func_00400D68();
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_005D8C88;
}
