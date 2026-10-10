#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00285338_arg0 {
    char pad0[0x74];
    f32 unk74;
    f32 unk78;
};

void func_00285338(struct func_00285338_arg0 *arg0) {
    arg0->unk74 = 0x1.0000000000000p+0f;
    arg0->unk78 = 0x1.9999980000000p-4f;
}
