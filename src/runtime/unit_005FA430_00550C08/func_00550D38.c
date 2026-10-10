#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00550D38_arg0 {
    char pad0[0x327A4];
    f32 unk327A4;
};

f32 func_00550D38(struct func_00550D38_arg0 *arg0) {
    return arg0->unk327A4;
}
