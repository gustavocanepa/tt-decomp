/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68(void *);                      /* extern */
s32 func_004A4DD8(void *);                      /* extern */
s32 func_004AC838(s32, void *);                 /* extern */

struct func_0056E318_arg1 {
    char pad0[0x80];
    s32 unk80;
};

void func_0056E318(s32 arg0, void *arg1) {
    func_004A4D68(arg1);
    ((struct func_0056E318_arg1 *)arg1)->unk80 = 0;
    func_004AC838(arg0 + 0x40, arg1 + 0x3C);
    func_004A4DD8(arg1);
}
