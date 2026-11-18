#include "types.h"

extern "C" s32 func_0047F230(void *arg0, s32 arg1);

extern "C" void hFileIO__write(char *arg0, s32 arg1, s32 arg2) {
    s32 spare[4];
    s32 buf[2];
    s32 *p;
    p = buf;
    p[0] = arg1;
    p[1] = arg2;
    func_0047F230(arg0 + 0x18, (s32)p);
}
