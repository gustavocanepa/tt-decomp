#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00200158();                            /* extern */

struct func_001C5B10_arg0 {
    char pad0[0x118];
    s32 unk118;
};

void func_001C5B10(struct func_001C5B10_arg0 *arg0) {
    func_00200158();
    arg0->unk118 = 1;
}
