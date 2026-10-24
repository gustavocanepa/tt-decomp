#include "types.h"

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A47C8;
extern char D_006183D0[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DC80(void) {
    if (D_005A47C8.unk0 == 0) {
        D_005A47C8.unk0 = D_006183D0;
        D_005A47C8.unk4 = D_005DB838;
    }
    return &D_005A47C8;
}
