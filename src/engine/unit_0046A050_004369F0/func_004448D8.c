#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004448D8_arg0 {
    char pad0[0x38];
    f32 unk38;
};

void func_004448D8(struct func_004448D8_arg0 *arg0, f32 fparg0) {
    arg0->unk38 = fparg0;
}
