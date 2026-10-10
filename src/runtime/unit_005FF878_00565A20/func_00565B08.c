#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00411D78(s32);                         /* extern */

struct func_00565B08_arg0 {
    char pad0[0x1EC];
    s32 unk1EC;
};

void func_00565B08(struct func_00565B08_arg0 *arg0) {
    func_00411D78(arg0->unk1EC);
}
