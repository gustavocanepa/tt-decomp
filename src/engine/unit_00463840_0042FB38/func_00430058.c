#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00430058_arg0 {
    char pad0[0x1B];
    s8 unk1B;
};

void func_00430058(struct func_00430058_arg0 *arg0) {
    arg0->unk1B = 2;
}
