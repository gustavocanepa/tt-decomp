#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003EBBF8(s32);                         /* extern */
s32 func_00457F18();                            /* extern */

struct func_003EEA98_arg0 {
    char pad0[0x11F4];
    s32 unk11F4;
    s32 unk11F8;
    s32 unk11FC;
    s32 unk1200;
    s32 unk1204;
};

void func_003EEA98(void *arg0) {
    func_00457F18();
    func_003EBBF8(arg0 + 0x11D4);
    ((struct func_003EEA98_arg0 *)arg0)->unk11F4 = 0;
    ((struct func_003EEA98_arg0 *)arg0)->unk11F8 = 0;
    ((struct func_003EEA98_arg0 *)arg0)->unk1200 = -1;
    ((struct func_003EEA98_arg0 *)arg0)->unk11FC = 0;
    ((struct func_003EEA98_arg0 *)arg0)->unk1204 = 0;
}
