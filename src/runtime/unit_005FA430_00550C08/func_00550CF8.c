#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550CF8_arg0 {
    char pad0[0x327C0];
    f32 unk327C0;
};

f32 func_00550CF8(struct func_00550CF8_arg0 *arg0) {
    return arg0->unk327C0;
}
