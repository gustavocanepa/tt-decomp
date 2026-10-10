#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00535718_arg0 {
    char pad0[0x74];
    f32 unk74;
};

void func_00535718(struct func_00535718_arg0 *arg0, f32 fparg0) {
    arg0->unk74 = fparg0;
}
