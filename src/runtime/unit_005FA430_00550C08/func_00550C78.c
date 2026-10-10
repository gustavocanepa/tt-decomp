#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550C78_arg0 {
    char pad0[0x327B8];
    f32 unk327B8;
};

void func_00550C78(struct func_00550C78_arg0 *arg0, f32 fparg0) {
    arg0->unk327B8 = fparg0;
}
