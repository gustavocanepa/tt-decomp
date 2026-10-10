/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00466828(void *, s32);                 /* extern */
s32 func_00467508(void *);                      /* extern */
s32 func_0046FB08(s32);                     /* extern */
s32 func_00472628();                            /* extern */
s32 func_004781B0(s32);                             /* extern */
s32 func_00478310(s32);                         /* extern */

struct func_001054E8_arg0 {
    s32 unk0;
    char pad4[0x30];
    s32 unk34;
};
struct func_001054E8_arg1 {
    char pad0[0x12];
    u16 unk12;
};

void func_001054E8(struct func_001054E8_arg0 *arg0, struct func_001054E8_arg1 *arg1) {
    s32 temp_v0;

    if (arg0->unk34 != 0) {
        func_00478310(arg0->unk0);
    }
    temp_v0 = func_004781B0(arg1->unk12 << 6);
    arg0->unk34 = 1;
    arg0->unk0 = temp_v0;
    func_00466828(arg1, temp_v0);
    func_00467508(arg1);
    func_0046FB08(1);
    func_00472628();
}
