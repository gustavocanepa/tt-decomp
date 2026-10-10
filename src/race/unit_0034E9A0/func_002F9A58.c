#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F9A58_arg0 {
    char pad0[0x7E4];
    f32 unk7E4;
};

void func_002F9A58(struct func_002F9A58_arg0 *arg0, f32 fparg0) {
    arg0->unk7E4 = fparg0;
}
