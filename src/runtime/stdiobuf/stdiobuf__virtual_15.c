#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004F5040(s32);                         /* extern */

struct stdiobuf__virtual_15_arg0 {
    char pad0[0x58];
    s32 unk58;
};

void stdiobuf__virtual_15(struct stdiobuf__virtual_15_arg0 *arg0) {
    func_004F5040(arg0->unk58);
    arg0->unk58 = 0;
}
