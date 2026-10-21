#include "types.h"

struct S005F3770 {
    char pad0[0x8C];
    s32 unk8C;
};

extern "C" char *func_005520C0(struct S005F3770 *arg0) {
    return (char *)arg0 + (arg0->unk8C * 0x44) + 4;
}
