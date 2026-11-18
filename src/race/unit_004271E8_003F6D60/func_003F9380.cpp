#include "types.h"

struct Obj004321B8 {
    s32 x;
    unsigned char pad[0x28];
};

extern "C" s32 func_003F9380(struct Obj004321B8 *arg0)
{
    s32 n = 0;
    s32 i;

    for (i = 0; i < 10; i++) {
        if (arg0[i].x != 0x157529FF) n++;
    }
    return n;
}
