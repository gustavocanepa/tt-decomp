#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002B1D28(void *, void *);              /* extern */
void *func_002BDA28(s32, s32);              /* extern */

extern char D_005C7250[];
struct func_002B1C70_temp_v0 {
    s32 unk0;
    s32 unk4;
};
struct func_002B1C70_arg0 {
    char pad0[0x20];
    s32 unk20;
};

void func_002B1C70(struct func_002B1C70_arg0 *arg0, s32 arg1) {
    struct func_002B1C70_temp_v0 *temp_v0;

    temp_v0 = func_002BDA28(8, 4);
    temp_v0->unk4 = (s32) arg0->unk20;
    temp_v0->unk0 = (s32)D_005C7250;
    arg0->unk20 = arg1;
    func_002B1D28(arg0, temp_v0);
}
