/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */
s32 func_004A4E08(s32);                         /* extern */

struct func_0047D8D8_arg0 {
    char pad0[0x1868];
    s32 unk1868;
};

void func_0047D8D8(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = arg0 + 0x1838;
    func_004A4D68(temp_s1);
    temp_v0 = ((struct func_0047D8D8_arg0 *)arg0)->unk1868 + 1;
    ((struct func_0047D8D8_arg0 *)arg0)->unk1868 = temp_v0;
    if (temp_v0 != 1) {
        func_004A4E08(temp_s1);
    }
    func_004A4DD8(temp_s1);
}
