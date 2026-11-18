#include "types.h"

struct Obj00494520 {
    char pad[0x98C];
    void *unk98C;
};

extern char D_005DA2C8[];
extern "C" s32 func_00462838(struct Obj00494520 *arg0);

extern "C" s32 func_00462778(struct Obj00494520 *arg0) {
    arg0->unk98C = D_005DA2C8;
    return func_00462838(arg0);
}
