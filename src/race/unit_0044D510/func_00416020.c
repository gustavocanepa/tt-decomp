#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00416020_arg0 {
    char pad0[0x10];
    f32 unk10;
    f32 unk14;
};

void func_00416020(struct func_00416020_arg0 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk10 = fparg0;
    arg0->unk14 = fparg1;
}
