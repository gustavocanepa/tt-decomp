#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00576248_arg0 {
    char pad0[0x10];
    s64 unk10;
};

s64 func_00576248(struct func_00576248_arg0 *arg0, s64 arg1) {
    s64 temp_v0;

    temp_v0 = arg0->unk10;
    arg0->unk10 = arg1;
    return temp_v0;
}
