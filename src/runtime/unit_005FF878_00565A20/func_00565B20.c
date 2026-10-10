#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00412610(s32);                         /* extern */

struct func_00565B20_arg0 {
    char pad0[0x1F0];
    s32 unk1F0;
};

void func_00565B20(struct func_00565B20_arg0 *arg0) {
    func_00412610(arg0->unk1F0);
}
