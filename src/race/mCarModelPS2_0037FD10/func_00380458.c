#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_00380458_arg0 {
    char pad0[0x884];
    s32 unk884;
};

void func_00380458(struct func_00380458_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk884;
    if (temp_v0 != 0) {
        func_004A45D0(temp_v0);
        arg0->unk884 = 0;
    }
}
