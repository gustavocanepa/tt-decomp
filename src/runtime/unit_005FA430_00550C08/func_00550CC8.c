#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550CC8_arg0 {
    char pad0[0x327B4];
    f32 unk327B4;
};

f32 func_00550CC8(struct func_00550CC8_arg0 *arg0) {
    return arg0->unk327B4;
}
