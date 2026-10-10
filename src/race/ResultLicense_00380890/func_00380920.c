#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00380950();                                /* extern */

struct func_00380920_arg0 {
    char pad0[0xD4C];
    s32 unkD4C;
};

s32 func_00380920(struct func_00380920_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_00380950();
    arg0->unkD4C = 1;
    return temp_v0 != 0;
}
