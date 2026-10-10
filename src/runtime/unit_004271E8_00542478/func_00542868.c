#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00542868_arg0 {
    char pad0[0x88];
    f32 unk88;
};

void func_00542868(struct func_00542868_arg0 *arg0, f32 fparg0) {
    arg0->unk88 = fparg0;
}
