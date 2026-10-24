#include "types.h"

extern char D_005F1720[];

struct Obj {
    u8 pad[0x10];
    char *unk10;
};

extern "C" char *func_002B01B0(Obj *arg0) {
    char **fieldPtr = &arg0->unk10;
    char *p = *fieldPtr;
    s32 len = *(s32 *)(p - 0x10);
    if (len == 0) {
        return D_005F1720;
    }
    p[len] = 0;
    return *fieldPtr;
}
