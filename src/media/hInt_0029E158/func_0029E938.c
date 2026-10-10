#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_002A77A8();                            /* extern */

struct func_0029E938_arg0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_0029E938_arg1 {
    char pad0[0x10];
    s32 unk10;
};

void *func_0029E938(struct func_0029E938_arg0 *arg0, struct func_0029E938_arg1 *arg1) {
    if (arg0 != arg1) {
        func_002A77A8();
        arg0->unk10 = (s32) arg1->unk10;
    }
    return arg0;
}
