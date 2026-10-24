#include "types.h"

typedef struct {
    s32 v;
    s32 pad;
} D0048EDDEntry;

extern D0048EDDEntry D_0076CE74[];

s32 func_00455960(u32 arg0) {
    if (arg0 < 0xCU) {
        return D_0076CE74[arg0].v;
    }
    return -1;
}
