#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00418608_arg0 {
    char pad0[0xEC];
    f32 unkEC;
};

void func_00418608(struct func_00418608_arg0 *arg0, f32 fparg0) {
    arg0->unkEC = fparg0;
}
