#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0045F1F0();                                /* extern */

struct func_0045F280_arg0 {
    char pad0[0x40];
    f32 unk40;
    char pad44[0x48];
    f32 unk8C;
};

f32 func_0045F280(struct func_0045F280_arg0 *arg0) {
    return func_0045F1F0() + (arg0->unk8C * arg0->unk40);
}
