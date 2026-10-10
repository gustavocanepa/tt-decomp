#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0033A098_arg0 {
    char pad0[0xD80];
    s32 unkD80;
};

void func_0033A098(void *arg0, s32 arg1) {
    ((struct func_0033A098_arg0 *)arg0)->unkD80 = (s32) ((arg1 != 0) ? arg1 : (arg0 + 0x80));
}
