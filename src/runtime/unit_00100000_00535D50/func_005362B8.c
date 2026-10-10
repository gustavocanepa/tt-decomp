#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005362B8_arg0 {
    char pad0[0x58];
    f32 unk58;
};

void func_005362B8(struct func_005362B8_arg0 *arg0, f32 fparg0) {
    arg0->unk58 = fparg0;
}
