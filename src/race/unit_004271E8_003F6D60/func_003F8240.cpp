#include "types.h"

extern "C" s32 func_003F8208(u32 arg0);

extern "C" s32 func_003F8240(u32 *arg0) {
    return func_003F8208(*arg0 & 0xF);
}
