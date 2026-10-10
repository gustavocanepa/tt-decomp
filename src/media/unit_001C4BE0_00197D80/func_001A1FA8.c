#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001A1E60(void *);                      /* extern */

struct func_001A1FA8_arg0 {
    char pad0[0xB4];
    s32 unkB4;
};

void func_001A1FA8(void *arg0) {
    func_001A1E60(arg0 + (((struct func_001A1FA8_arg0 *)arg0)->unkB4 * 0x2C) + 0xB8);
    ((struct func_001A1FA8_arg0 *)arg0)->unkB4 = (s32) (((struct func_001A1FA8_arg0 *)arg0)->unkB4 + 1);
}
