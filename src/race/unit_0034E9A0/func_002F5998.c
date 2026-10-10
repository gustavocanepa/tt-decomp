#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F5998_arg0 {
    char pad0[0x534];
    f32 unk534;
    char pad538[0xA];
    s8 unk542;
};

void func_002F5998(struct func_002F5998_arg0 *arg0) {
    if (arg0->unk534 == 0x0.0p+0f) {
        arg0->unk542 = 0;
        return;
    }
    arg0->unk542 = 1;
}
