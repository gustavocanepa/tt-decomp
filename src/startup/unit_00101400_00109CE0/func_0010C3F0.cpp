#include "types.h"
#define NULL 0
#include "m2c_macros.h"

extern "C" {
void func_00370880(char *arg0);             /* extern */

struct func_0010C3F0_list {
    s32 count;
    char pad4[4];
    s32 items;
};

void func_0010C3F0(char *arg0) {
    s32 i;
    s32 n;
    s32 off;

    n = (*(struct func_0010C3F0_list **)(arg0 + 0x60))->count;
    i = 0;
    if (n > 0) {
        do {
            off = i * 4;
            i += 1;
            func_00370880((char *)(*(s32 *)(off + (*(struct func_0010C3F0_list **)(arg0 + 0x60))->items)) + 0x1264);
            func_00370880((char *)(*(s32 *)(off + (*(struct func_0010C3F0_list **)(arg0 + 0x60))->items)) + 0x1220);
        } while (i < n);
    }
}

}
