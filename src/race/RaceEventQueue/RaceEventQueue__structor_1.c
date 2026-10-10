#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D1590[];
struct RaceEventQueue {
    char unk_0[0x828];
    void * unk828;
};
s32 func_0050E1A8(struct RaceEventQueue *);     /* extern */

void RaceEventQueue__structor_1(struct RaceEventQueue *arg0, s32 arg1) {
    arg0->unk828 = (void *)(s32)D_005D1590;
    func_004A48D8(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
