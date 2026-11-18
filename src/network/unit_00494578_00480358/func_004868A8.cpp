#include "types.h"

extern const u16 D_00605B98[];
extern const u16 D_00605BE8[];

static inline void ustrcpy(u16 *d, const u16 *s) {
    while ((*d++ = *s++) != 0)
        ;
}

extern "C" int func_004868A8(u16 *dst, int c) {
    const u16 *src = 0;
    if (c == 'n' || c == 'N')
        src = D_00605B98;
    else if (c == 'k' || c == 'K')
        src = D_00605BE8;
    if (src) {
        ustrcpy(dst, src);
        return 1;
    }
    *dst = 0;
    return 0;
}
