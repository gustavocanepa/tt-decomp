#include "types.h"

extern s32 GT4Model__BinStreamBase__get(void);

u8 GT4Model__BinStreamReader__read8u(void) {
    return (u8)GT4Model__BinStreamBase__get();
}
