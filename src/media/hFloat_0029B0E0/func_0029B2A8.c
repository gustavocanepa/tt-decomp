#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002A77A8();                            /* extern */

struct func_0029B2A8_arg0 {
    char pad0[0x10];
    f32 unk10;
};
struct func_0029B2A8_arg1 {
    char pad0[0x10];
    f32 unk10;
};

void *func_0029B2A8(struct func_0029B2A8_arg0 *arg0, struct func_0029B2A8_arg1 *arg1) {
    if (arg0 != arg1) {
        func_002A77A8();
        arg0->unk10 = (f32) arg1->unk10;
    }
    return arg0;
}
