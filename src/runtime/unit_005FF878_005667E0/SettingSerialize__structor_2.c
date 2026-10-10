#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D9A00[];
struct SettingSerialize {
    /* 0x00 */ void *unk0;
    /* 0x04 */ char pad4[4];
    /* 0x08 */ s32 unk8;                        /* inferred */
    /* 0x08 */ char pad8[0x5C];
    /* 0x64 */ void *unk64;
    /* 0x68 */ char pad68[4];
    /* 0x6C */ s32 unk6C;
};                                                  /* size = 0x70 */

s32 func_0040BBD0(s32 *);                   /* extern */

void SettingSerialize__structor_2(struct SettingSerialize *arg0) {
    func_0042F4B0(arg0);
    arg0->unk0 = (void *)(s32)D_005D9A00;
    func_0040BBD0(&arg0->unk8);
}
