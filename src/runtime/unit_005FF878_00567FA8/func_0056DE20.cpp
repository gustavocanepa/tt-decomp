#include "types.h"

extern "C" s32 func_0056DE20(u8 *arg0) {
    u8 *p = arg0 + 8;
    return (p[0] | (p[1] << 8) | (p[2] << 16)) | (p[3] << 24);
}
