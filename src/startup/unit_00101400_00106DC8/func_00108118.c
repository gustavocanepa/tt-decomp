#include "types.h"

struct Result { s32 pad[4]; void *p; s32 pad14[3]; };
extern void *D_00579744;
extern s32 D_00579750;
void func_0047DB20(struct Result *, s32, s32);
void func_00466B28(void *);

void func_00108118(void) {
    void **pg = &D_00579744;
    if (*pg == 0) {
        struct Result r;
        func_0047DB20(&r, D_00579750, 1);
        *pg = r.p;
        func_00466B28(r.p);
    }
}
