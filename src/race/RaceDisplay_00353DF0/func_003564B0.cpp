#include "types.h"

struct Holder {
    char p00[0x34];
    s32 f34;
};

extern "C" void func_0035A5F0(void *a0, const char *a1, s32 a2);
extern "C" void RaceEventDisplay__addEvent(char *self, s32 a1, f32 delta, f32 value, f32 a, f32 b);

extern char D_005F44E8[];
extern struct Holder *D_00584418;

extern "C" void func_003564B0(void *arg0) {
    char *s0;

    s0 = (char *)arg0 + 0x177C;
    *(s32 *)(s0 + 0x20) = (s32)0x80C8C8C8;
    func_0035A5F0(s0, D_005F44E8, 1);
    RaceEventDisplay__addEvent(s0, D_00584418->f34, 3.0f, 0.0f, 0.1499999910593033f, 0.1499999910593033f);
}
