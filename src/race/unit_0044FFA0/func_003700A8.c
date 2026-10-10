#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003700A8_arg0 {
    char pad0[0xD40];
    s32 unkD40;
};

void func_003700A8(struct func_003700A8_arg0 *arg0) {
    arg0->unkD40 = (s32) (arg0->unkD40 == 0);
}
