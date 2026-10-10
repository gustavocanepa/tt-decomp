#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0036F300(void *);                      /* extern */
s32 func_0036F588();                      /* extern */

extern char D_005D2670[];
struct func_0036F6C8_arg0 {
    char pad0[0xD40];
    s32 unkD40;
    s32 unkD44;
    s32 unkD48;
    s32 unkD4C;
    s32 unkD50;
    s32 unkD54;
    char padD58[0x7C];
    s32 unkDD4;
    s32 unkDD8;
    s32 unkDDC;
    s32 unkDE0;
    s32 unkDE4;
    s32 unkDE8;
    s32 unkDEC;
};

void func_0036F6C8(void *arg0) {
    ((struct func_0036F6C8_arg0 *)arg0)->unkDEC = (s32)D_005D2670;
    func_0036F588();
    func_0036F588(arg0 + 0x6A0);
    ((struct func_0036F6C8_arg0 *)arg0)->unkD40 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkD44 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkD48 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkD4C = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkD50 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkD54 = 0;
    func_0036F300(arg0 + 0xD58);
    ((struct func_0036F6C8_arg0 *)arg0)->unkDDC = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkDE0 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkDE4 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkDE8 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkDD4 = 0;
    ((struct func_0036F6C8_arg0 *)arg0)->unkDD8 = 0;
}
