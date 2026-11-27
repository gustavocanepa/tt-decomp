#include "types.h"

extern void *D_005D5D30;
extern "C" void *func_00393550(void *);

struct func_00393570_arg0 {
    char pad0[0x4];
    void *unk4;
};

struct func_00393570_r0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *func_00393570(struct func_00393570_arg0 *arg0) {
    void *r0 = func_00393550(arg0);
    if (r0 != 0) {
        ((struct func_00393570_r0 *)r0)->unk4 = &D_005D5D30;
        *(void **)(r0) = arg0->unk4;
        arg0->unk4 = r0;
    }
    return r0;
}
