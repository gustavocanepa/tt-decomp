#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00483528_arg0 {
    char pad0[0x85C];
    s32 unk858;
};
struct func_00483528_temp_v0 {
    char pad0[0x418];
    s32 unk418;
};

void *func_00483528(void *arg0) {
    char *temp_v0;
    s32 n;

    temp_v0 = (char *)arg0 + ((1 - ((struct func_00483528_arg0 *)arg0)->unk858) * 0x41C) + 0x24;
    n = ((struct func_00483528_temp_v0 *)temp_v0)->unk418;
    n = n + 1;
    return temp_v0 + (n * 8) + 0x218;
}
