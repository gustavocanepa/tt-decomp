#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A5618(void *);                      /* extern */
void *func_004A56C8();                              /* extern */

struct func_004AF420_temp_v0 {
    char pad0[0x40];
    s32 unk40;
};

void *func_004AF420(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct func_004AF420_temp_v0 *temp_v0;

    temp_v0 = func_004A56C8();
    temp_v0->unk40 = arg3;
    func_004A5618(temp_v0);
    return temp_v0;
}
