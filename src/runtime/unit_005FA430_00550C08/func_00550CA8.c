#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550CA8_arg0 {
    char pad0[0x327C4];
    f32 unk327C4;
};

void func_00550CA8(struct func_00550CA8_arg0 *arg0, f32 fparg0) {
    arg0->unk327C4 = fparg0;
}
