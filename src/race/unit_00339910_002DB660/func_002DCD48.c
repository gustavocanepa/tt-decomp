#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 GT4Model__BinStreamReader__read8u(void *);                      /* extern */
s32 func_00423EC8(void *);                      /* extern */
s32 func_004242C0(void *, void *);              /* extern */
s32 func_00424408(void *, void *, s32);     /* extern */

extern char D_005F2AF0[];
struct func_002DCD48_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_002DCD48(struct func_002DCD48_arg0 *arg0) {
    s32 frag1;
    s8 sp[0x10];
    s32 temp_s1;

    frag1 = arg0->unk0;
    temp_s1 = arg0->unk8 - frag1;
    func_00424408(sp, arg0, (s32)D_005F2AF0);
    func_004242C0(sp, arg0);
    GT4Model__BinStreamReader__read8u(arg0);
    func_00423EC8(arg0);
    func_00423EC8(arg0);
    GT4Model__BinStreamReader__read8u(arg0);
    arg0->unk8 = (s32) (arg0->unk0 + temp_s1);
}
