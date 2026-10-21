#include "types.h"

struct S00659988 {
    void *unk0;
    void *unk4;
};

extern struct S00659988 D_005A4810;
extern char D_00618418[];
extern char D_005DB838[];

extern "C" struct S00659988 *func_0050DE78(void) {
    if (D_005A4810.unk0 == 0) {
        D_005A4810.unk0 = D_00618418;
        D_005A4810.unk4 = D_005DB838;
    }
    return &D_005A4810;
}
