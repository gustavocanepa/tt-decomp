#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00417D00_arg0 {
    char pad0[0x138];
    f32 unk138;
};

void func_00417D00(struct func_00417D00_arg0 *arg0, f32 fparg0) {
    arg0->unk138 = fparg0;
}
