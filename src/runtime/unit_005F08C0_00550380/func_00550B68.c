#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550B68_arg0 {
    char pad0[0x1044];
    f32 unk1044;
};

void func_00550B68(struct func_00550B68_arg0 *arg0, f32 fparg0) {
    arg0->unk1044 = fparg0;
}
