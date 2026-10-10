#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004834E8_arg0 {
    char pad0[0x85C];
    s32 unk85C;
};
struct func_004834E8_temp_v0 {
    char pad0[0x418];
    s32 unk418;
};

void *func_004834E8(void *arg0) {
    void *temp_v0;

    temp_v0 = arg0 + ((1 - ((struct func_004834E8_arg0 *)arg0)->unk85C) * 0x41C) + 0x24;
    return temp_v0 + (((struct func_004834E8_temp_v0 *)temp_v0)->unk418 * 8) + 0x218;
}
