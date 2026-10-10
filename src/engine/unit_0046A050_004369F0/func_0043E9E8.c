#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00442728(void *);                      /* extern */
s32 func_0044B7F0(s32);                         /* extern */

struct func_0043E9E8_arg0 {
    s32 unk0;
    s32 unk4;
};

void func_0043E9E8(void *arg0) {
    s32 temp_v1;

    temp_v1 = ((struct func_0043E9E8_arg0 *)arg0)->unk0;
    switch (temp_v1) {                              /* irregular */
    case 7:
        func_0044B7F0(((struct func_0043E9E8_arg0 *)arg0)->unk4);
        return;
    case 10:
        func_00442728(arg0 + 4);
        return;
    }
}
