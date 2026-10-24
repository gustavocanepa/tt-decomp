#include "types.h"

extern "C" s32 func_0056DDC0(u8 *arg0, s32 arg1) {
    u8 *p = arg0 + arg1;
    return (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24);
}
