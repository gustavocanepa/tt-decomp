#include "types.h"
#define NULL 0

void func_0047C698(void *item);                 /* extern */
void func_004AE9F0(void *, s32);                /* extern */
void func_004AC770(void *, s32);                /* extern */
void func_0050E1A8(void *);                     /* extern */

extern char D_005DA4F8[];
extern char D_005DA5C8[];

struct func_0047CAD0_arg0 {
    char pad0[0xA4];
    s32 unkA4;
};

struct func_0047CAD0_sub {
    char pad0[8];
    s32 unk8;
};

void func_0047CAD0(void *arg0, s32 arg1) {
    struct func_0047CAD0_sub *temp_v0;
    struct func_0047CAD0_sub *temp_a0;
    struct func_0047CAD0_sub *temp_a0_2;

    ((struct func_0047CAD0_arg0 *)arg0)->unkA4 = (s32)D_005DA4F8;
    func_0047C698(arg0);
    func_004AE9F0((char *)arg0 + 0x64, 2);
    temp_v0 = (struct func_0047CAD0_sub *)((char *)arg0 + 0x58);
    temp_v0->unk8 = (s32)D_005DA5C8;
    func_004AC770(temp_v0, 0);
    temp_a0 = (struct func_0047CAD0_sub *)((char *)arg0 + 0x4C);
    temp_a0->unk8 = (s32)D_005DA5C8;
    func_004AC770(temp_a0, 0);
    temp_a0_2 = (struct func_0047CAD0_sub *)((char *)arg0 + 0x40);
    temp_a0_2->unk8 = (s32)D_005DA5C8;
    func_004AC770(temp_a0_2, 0);
    func_004AE9F0((char *)arg0 + 0x10, 2);
    if (arg1 & 1) {
        return func_0050E1A8(arg0);
    }
}
