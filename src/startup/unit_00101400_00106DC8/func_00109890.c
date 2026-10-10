/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */
s32 func_004A4E08(s32);                         /* extern */

struct func_00109890_arg0 {
    char pad0[0xA0];
    s32 unkA0;
};

void func_00109890(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x6C;
    func_004A4D68(temp_s1);
    if (((struct func_00109890_arg0 *)arg0)->unkA0 != 0) {
        func_004A4E08(temp_s1);
    }
    func_004A4DD8(temp_s1);
}
