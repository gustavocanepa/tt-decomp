#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005A63F8[];
void func_00132268(void *);
s32 func_002A7618(void *);
void func_00411E18(void *);
struct func_00132618_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x8];
    s32 unk10;
    s32 unk14;
};

void func_00132618(void *arg0, s32 arg1) {
    func_002A7618(arg0);
    ((struct func_00132618_arg0 *)arg0)->unk4 = (s32)D_005A63F8;
    ((struct func_00132618_arg0 *)arg0)->unk14 = arg1;
    ((struct func_00132618_arg0 *)arg0)->unk10 = 0;
    func_00411E18((s8 *)arg0 + 0x18);
    func_00132268(arg0);
}
