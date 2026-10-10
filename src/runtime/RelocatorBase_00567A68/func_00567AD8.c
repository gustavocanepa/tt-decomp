#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00567AD8_arg0 {
    char pad0[0x78];
    f32 unk78;
};

void func_00567AD8(struct func_00567AD8_arg0 *arg0, f32 fparg0) {
    arg0->unk78 = fparg0;
}
