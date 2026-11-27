#include "types.h"

extern "C" void func_001AB7A0(void *arg0, void *arg1);
extern "C" char D_005E4AA0[];

extern "C" void func_0017BB90(void *arg0, void **arg1) {
    void *obj = *arg1;
    s32 off = *(s32 *)((char *)obj - 0x10);
    void *a1v;
    if (off == 0) {
        a1v = D_005E4AA0;
    } else {
        char *p = (char *)obj + off;
        *p = 0;
        a1v = *arg1;
    }
    func_001AB7A0((char *)arg0 + 0xB3C, a1v);
}
