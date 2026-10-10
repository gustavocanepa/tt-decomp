#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004AE9C0(void *);                      /* extern */

struct func_00102760_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x60];
    s32 unk68;
};

void func_00102760(void *arg0, s32 arg1) {
    ((struct func_00102760_arg0 *)arg0)->unk0 = arg1;
    ((struct func_00102760_arg0 *)arg0)->unk4 = 1;
    func_004AE9C0(arg0 + 8);
    func_004AE9C0(arg0 + 0x38);
    ((struct func_00102760_arg0 *)arg0)->unk68 = 0;
}
