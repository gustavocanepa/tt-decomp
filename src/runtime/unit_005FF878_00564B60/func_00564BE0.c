#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00564BE0_arg0 {
    char pad0[0x78];
    s64 unk78;
};

s64 func_00564BE0(struct func_00564BE0_arg0 *arg0) {
    return arg0->unk78;
}
