#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0041B058_arg0 {
    char pad0[0x94];
    f32 unk94;
};

void func_0041B058(struct func_0041B058_arg0 *arg0, f32 fparg0) {
    arg0->unk94 = fparg0;
}
