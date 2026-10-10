#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00511358_arg0 {
    char pad0[0x2A4];
    s32 unk2A4;
};

s32 func_00511358(struct func_00511358_arg0 *arg0) {
    return arg0->unk2A4;
}
