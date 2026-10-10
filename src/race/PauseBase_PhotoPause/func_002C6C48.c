#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00106AF0(s32, s32, s32, s32, s32); /* extern */
void *func_002C6290(void *);                        /* extern */
s32 func_002C6298(void *);                          /* extern */
s32 func_002C69E8();                            /* extern */
s32 func_0031AB48(s32, s32, s32);       /* extern */
s32 func_0031C6C0(s32, s32);                /* extern */

extern char D_002C6BF8[];
extern char D_002C6C20[];
extern char D_005794F0[];
struct func_002C6C48_temp_v0 {
    char pad0[0xE44];
    s32 unkE44;
    void *unkE48;
};
struct func_002C6C48_temp_v0_2 {
    char pad0[0xE4C];
    s32 unkE4C;
    void *unkE50;
};
struct func_002C6C48_arg0 {
    char pad0[0x2B4];
    s32 unk2B4;
};

void func_002C6C48(struct func_002C6C48_arg0 *arg0) {
    struct func_002C6C48_temp_v0 *temp_v0;
    struct func_002C6C48_temp_v0_2 *temp_v0_2;

    func_002C69E8();
    func_0031AB48(func_002C6298(arg0), 0, 0);
    func_0031C6C0(func_002C6298(arg0), 1);
    temp_v0 = func_002C6290(arg0);
    temp_v0->unkE48 = arg0;
    temp_v0->unkE44 = (s32)D_002C6BF8;
    temp_v0_2 = func_002C6290(arg0);
    temp_v0_2->unkE50 = arg0;
    temp_v0_2->unkE4C = (s32)D_002C6C20;
    func_00106AF0((s32)D_005794F0, 1, 2, 0x280, 0x1C0);
    arg0->unk2B4 = 4;
}
