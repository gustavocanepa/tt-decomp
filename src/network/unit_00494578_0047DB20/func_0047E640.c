/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68();                            /* extern */
s32 func_004A4DD8(void *);                      /* extern */
s32 func_004AC838(s32, void *);                 /* extern */

struct func_0047E640_arg1 {
    char pad0[0x50];
    void *unk50;
};
struct func_0047E640_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_0047E640(void *arg0, void *arg1) {
    func_004A4D68();
    ((struct func_0047E640_arg1 *)arg1)->unk50 = arg0;
    func_004AC838(arg0 + 0xAC, arg1 + 0x54);
    ((struct func_0047E640_arg0 *)arg0)->unk80 = 0;
    func_004A4DD8(arg0);
}
