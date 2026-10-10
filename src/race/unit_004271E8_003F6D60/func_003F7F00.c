#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F8068(void *, s32);             /* extern */
s32 func_004026C8(s32);                         /* extern */
s32 func_00402870(s32);                         /* extern */

struct func_003F7F00_arg0 {
    s64 unk0;
    s8 unk8;
    char pad9[0x3F];
    s32 unk48;
    char pad4C[0x88];
    s32 unkD4;
    s32 unkD8;
    char padDC[0x8];
    s32 unkE4;
    s32 unkE8;
};

s32 func_003F7F00(void *arg0) {
    func_004026C8(arg0 + 0x4C);
    func_00402870(arg0 + 0xA0);
    ((struct func_003F7F00_arg0 *)arg0)->unk0 = -1;
    ((struct func_003F7F00_arg0 *)arg0)->unk8 = 0;
    ((struct func_003F7F00_arg0 *)arg0)->unk48 = 0;
    ((struct func_003F7F00_arg0 *)arg0)->unkD4 = 0;
    ((struct func_003F7F00_arg0 *)arg0)->unkD8 = 0;
    func_003F8068(arg0, 1);
    ((struct func_003F7F00_arg0 *)arg0)->unkE4 = 0;
    ((struct func_003F7F00_arg0 *)arg0)->unkE8 = -1;
}
