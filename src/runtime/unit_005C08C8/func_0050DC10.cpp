#include "types.h"

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A47B8;
extern char D_006183C0[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DC10(void) {
    if (D_005A47B8.unk0 == 0) {
        D_005A47B8.unk0 = D_006183C0;
        D_005A47B8.unk4 = D_005DB838;
    }
    return &D_005A47B8;
}
