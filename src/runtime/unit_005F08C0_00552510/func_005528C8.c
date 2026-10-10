#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005528C8_arg0 {
    char pad0[0x20A48];
    f32 unk20A48;
};

void func_005528C8(struct func_005528C8_arg0 *arg0, f32 fparg0) {
    arg0->unk20A48 = fparg0;
}
