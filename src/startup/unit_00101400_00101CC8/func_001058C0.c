#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104E00(void *);                      /* extern */

struct func_001058C0_temp_a0 {
    char pad0[0x78];
    s32 unk78;
};

void func_001058C0(s32 arg0) {
    void *temp_a0;

    temp_a0 = arg0 + 0xC0;
    func_00104E00(temp_a0 + (((struct func_001058C0_temp_a0 *)temp_a0)->unk78 * 0x3C));
}
