#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005607D0_arg0 {
    char pad0[0xABC];
    s32 unkABC;
    char padAC0[0x740];
    s32 unk1200;
};

s32 func_005607D0(struct func_005607D0_arg0 *arg0) {
    return arg0->unkABC + arg0->unk1200;
}
