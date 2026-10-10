#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0021A840_arg0 {
    char pad0[0x24];
    f32 unk24;
};

void func_0021A840(struct func_0021A840_arg0 *arg0, f32 fparg0) {
    arg0->unk24 = fparg0;
}
