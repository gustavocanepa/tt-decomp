#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00339090();                            /* extern */
s32 RacePause__structor_0(s32);                         /* extern */

extern char D_005CBCD0[];
struct RaceArcadeDemo__structor_0_arg0 {
    char pad0[0x64];
    s32 unk64;
};

void RaceArcadeDemo__structor_0(void *arg0) {
    func_00339090();
    ((struct RaceArcadeDemo__structor_0_arg0 *)arg0)->unk64 = (s32)D_005CBCD0;
    RacePause__structor_0(arg0 + 0x39AC0);
}
