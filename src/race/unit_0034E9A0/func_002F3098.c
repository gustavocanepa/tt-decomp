#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern u8 D_005839A4;
struct func_002F3098_p {
    char pad0[0xD0];
    f32 unkD0;
};

f32 func_002F3098(s16 *p, f32 x) {
    if (D_005839A4 != 0) {
        f32 a = ((f32 *)(p + 4))[*p];
        a = a * a;
        return ((struct func_002F3098_p *)p)->unkD0 * (x * x + a * 0x1.C71C70p-4f) / a;
    }
    return ((struct func_002F3098_p *)p)->unkD0 * x;

}
