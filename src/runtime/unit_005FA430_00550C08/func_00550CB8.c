#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550CB8_arg0 {
    char pad0[0x327B0];
    s32 unk327B0;
};

s32 func_00550CB8(struct func_00550CB8_arg0 *arg0) {
    return arg0->unk327B0;
}
