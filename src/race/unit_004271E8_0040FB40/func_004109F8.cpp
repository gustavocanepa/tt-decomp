#include "types.h"

struct Global;
extern Global D_00585A30;

struct Ref {
    s64 id;
    char pad8[0x18];
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, void *info);

extern "C" s32 func_004109F8(s64 id, void *out) {
    if ((id >> 32) == 0x26) {
        Ref r;
        if (SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, &r) == 0) {
            return 0;
        }
        id = r.id;
    }
    return SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, out) != 0;
}
