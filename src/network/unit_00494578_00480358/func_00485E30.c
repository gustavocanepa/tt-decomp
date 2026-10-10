#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00485E30_arg0 {
    char pad0[0x860];
    s32 unk860;
    s32 unk864;
};

void func_00485E30(struct func_00485E30_arg0 *arg0) {
    arg0->unk860 = 0;
    arg0->unk864 = 1;
}
