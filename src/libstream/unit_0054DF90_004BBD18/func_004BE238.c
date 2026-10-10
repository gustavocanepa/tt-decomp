#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004CC2A0(void *);                      /* extern */
s32 func_004FA840(s32);                         /* extern */
s32 func_004FA860(s32);                         /* extern */

struct func_004BE238_arg0 {
    char pad0[0x38];
    s32 unk38;
};

s32 func_004BE238(struct func_004BE238_arg0 *arg0) {
    func_004FA860(arg0->unk38);
    func_004CC2A0(arg0);
    func_004FA840(arg0->unk38);
    return 0;
}
