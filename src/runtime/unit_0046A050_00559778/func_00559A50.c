#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559A50_arg0 {
    char pad0[0x117E];
    s8 unk117E;
};

void func_00559A50(struct func_00559A50_arg0 *arg0, s8 arg1) {
    arg0->unk117E = arg1;
}
