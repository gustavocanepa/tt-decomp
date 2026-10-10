#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001B9298(void *, s32);             /* extern */
s32 func_0020DCA0(void *, s32);             /* extern */
s32 func_0022FD88();                            /* extern */
s32 func_00275968(s32, s32, s32);           /* extern */

extern char D_005BF620[];
extern char D_005BF9E0[];
struct func_00276510_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x24];
    s32 unk2C;
    char pad30[0xB0];
    f32 unkE0;
    f32 unkE4;
    s32 unkE8;
    s32 unkEC;
    s32 unkF0;
    char padF4[0x70];
    s32 unk164;
    s32 unk168;
    s32 unk16C;
    s32 unk170;
};

void func_00276510(void *arg0) {
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = arg0 + 0x12C;
    temp_s2 = arg0 + 0xF4;
    func_0022FD88();
    ((struct func_00276510_arg0 *)arg0)->unk4 = (s32)D_005BF620;
    ((struct func_00276510_arg0 *)arg0)->unkE0 = 0x1.3333320000000p-2f;
    ((struct func_00276510_arg0 *)arg0)->unkE4 = 0x1.0000000000000p+3f;
    ((struct func_00276510_arg0 *)arg0)->unk2C = (s32)D_005BF9E0;
    ((struct func_00276510_arg0 *)arg0)->unkE8 = 0;
    ((struct func_00276510_arg0 *)arg0)->unkEC = 0;
    ((struct func_00276510_arg0 *)arg0)->unkF0 = 0;
    func_00275968(temp_s2, 1, temp_s1);
    func_00275968(temp_s1, 0, temp_s2);
    ((struct func_00276510_arg0 *)arg0)->unk164 = 0;
    ((struct func_00276510_arg0 *)arg0)->unk168 = 0;
    ((struct func_00276510_arg0 *)arg0)->unk16C = 0;
    ((struct func_00276510_arg0 *)arg0)->unk170 = 0;
    func_001B9298(arg0, 0);
    func_0020DCA0(arg0, 0);
}
