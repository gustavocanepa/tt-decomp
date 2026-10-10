#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D8F38[];
s32 func_00400D68(s32 *);
void func_00400630(s32 *arg0) {
    s32 i;
    func_00400D68(arg0);
    *arg0 = (s32)D_005D8F38;
    for (i = 28; i >= 0; i--) {
        arg0[1 + i] = 0;
    }
}
