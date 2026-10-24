#include "types.h"

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A4840;
extern char D_00618448[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DFC8(void) {
    if (D_005A4840.unk0 == 0) {
        D_005A4840.unk0 = D_00618448;
        D_005A4840.unk4 = D_005DB838;
    }
    return &D_005A4840;
}
