#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004CEAE0(s32, void *);                 /* extern */

extern char D_005A0890[];
struct func_004CEA90_arg0 {
    char pad0[0x58];
    s32 unk58;
};

s32 func_004CEA90(struct func_004CEA90_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = (arg0->unk58 * 0x68) + (s32)D_005A0890;
    func_004CEAE0(temp_s0, arg0);
    return temp_s0;
}
