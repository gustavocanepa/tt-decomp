#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00400D68();                            /* extern */
s32 func_00402448(void *);                      /* extern */

extern char D_005D93E0[];
struct func_00402408_arg0 {
    s32 unk0;
    char pad4[0x20];
    s32 unk24;
};

void func_00402408(struct func_00402408_arg0 *arg0) {
    func_00400D68();
    arg0->unk0 = (s32)D_005D93E0;
    func_00402448(arg0);
    arg0->unk24 = 0;
}
