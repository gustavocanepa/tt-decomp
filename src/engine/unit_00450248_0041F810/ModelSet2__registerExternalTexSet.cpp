#include "types.h"

extern "C" s32 D_00769D28[16];

extern "C" void ModelSet2__registerExternalTexSet(s32 arg0, s32 arg1) {
    if (arg0 < 0x10) {
        D_00769D28[arg0] = arg1;
    }
}
