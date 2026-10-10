#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_004BBF58_arg0 {
    char pad0[0x190];
    s32 unk190;
};

void func_004BBF58(struct func_004BBF58_arg0 *arg0) {
    func_004A45D0(arg0->unk190);
    arg0->unk190 = 0;
}
