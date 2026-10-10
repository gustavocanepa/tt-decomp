/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0047CD30(s32, void *);                 /* extern */
s32 func_004A4D68(void *);                      /* extern */
s32 func_004A4DD8(void *);                      /* extern */
s32 func_004AC9B8(s32, void *);                 /* extern */

struct func_0047CF68_arg1 {
    char pad0[0x80];
    s32 unk80;
};

void func_0047CF68(s32 arg0, void *arg1) {
    void *temp_s2;

    temp_s2 = arg0 + 0x10;
    func_004A4D68(temp_s2);
    func_004A4D68(arg1);
    func_004AC9B8(arg0 + 0x4C, arg1 + 0x3C);
    ((struct func_0047CF68_arg1 *)arg1)->unk80 = 0;
    func_004A4DD8(arg1);
    func_0047CD30(arg0, arg1);
    func_004A4DD8(temp_s2);
}
