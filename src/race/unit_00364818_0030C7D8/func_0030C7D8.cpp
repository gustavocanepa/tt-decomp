#include "types.h"

struct Inner {
    char pad[0x1768];
    f32 unk1700;
    char pad2[0x1770 - 0x1768 - 4];
    u16 unk1708;
};

extern "C" f32 func_0030C7D8(void **arg0, s32 *arg1) {
    void * volatile *p = arg0;
    volatile s32 *out = arg1;
    *out = (s32)((Inner *)*p)->unk1708;
    return ((Inner *)*p)->unk1700;
}
