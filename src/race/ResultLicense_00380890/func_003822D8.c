#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s8 func_00381D08(s8, s32);                      /* extern */

struct func_003822D8_arg0 {
    s8 unk0;
    char pad1[0xB];
    s16 unkC;
    char padE[0xE];
    s8 unk1C;
};

void func_003822D8(struct func_003822D8_arg0 *arg0, s16 arg1) {
    arg0->unkC = arg1;
    arg0->unk1C = func_00381D08(arg0->unk0, 0);
}
