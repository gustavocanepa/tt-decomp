#include "types.h"

extern "C" void GT4Model__BinStreamReader__readArray(s32 arg0, char *arg1, s32 arg2);

extern "C" u16 func_00423DE0(s32 arg0) {
    u16 local;
    GT4Model__BinStreamReader__readArray(arg0, (char *)&local, 2);
    return local;
}
