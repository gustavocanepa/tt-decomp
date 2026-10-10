#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0035D650_arg0 {
    char pad0[0xCC];
    f32 unkCC;
};

void func_0035D650(struct func_0035D650_arg0 *arg0, f32 fparg0) {
    arg0->unkCC = fparg0;
}
