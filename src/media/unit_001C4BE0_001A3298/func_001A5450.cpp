#include "types.h"

struct Entry { s32 id; s32 a, b, c; };
extern Entry D_005E7C80[];

extern "C" Entry *func_001A5450(s32 id) {
    u32 i;
    for (i = 0; i < 6; i++) {
        if (id == D_005E7C80[i].id) return &D_005E7C80[i];
    }
    return D_005E7C80;
}
