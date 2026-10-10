#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004AFEB8(f32, f32, f32);                   /* extern */

struct func_004AFF28_arg0 {
    char pad0[0x8];
    f32 unk8;
};

void *func_004AFF28(struct func_004AFF28_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk8 = func_004AFEB8(arg0->unk8, fparg0, fparg1);
    return arg0;
}
