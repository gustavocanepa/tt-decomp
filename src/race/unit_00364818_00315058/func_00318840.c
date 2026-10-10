#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_00318728();                                /* extern */

struct func_00318840_arg0 {
    char pad0[0x8];
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

f32 func_00318840(struct func_00318840_arg0 *arg0) {
    return (func_00318728() * arg0->unk10 * arg0->unk8) / arg0->unkC;
}
