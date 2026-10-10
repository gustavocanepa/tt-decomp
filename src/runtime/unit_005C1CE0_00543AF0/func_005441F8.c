#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005441F8_arg0 {
    char pad0[0x50];
    f32 unk50;
};

f32 func_005441F8(struct func_005441F8_arg0 *arg0) {
    return arg0->unk50;
}
