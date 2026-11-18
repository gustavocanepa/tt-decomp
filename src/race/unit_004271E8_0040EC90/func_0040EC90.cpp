#include "types.h"

struct Global;
extern Global D_00585A30;

struct Obj {
    s64 ref;
    char pad8[0x90 + 8];
    s64 cur;
};

extern "C" s32 func_0040B980(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, void *info);
extern "C" void func_0040EC68(Obj *self);
extern "C" s32 func_0040EDE0(Obj *self, s64 ref);

extern "C" s32 func_0040EC90(Obj *self, s64 id) {
    if (self->cur == id) {
        return 1;
    }
    if (func_0040B980(&D_00585A30, id) == 0) {
        return 0;
    }
    func_0040EC68(self);
    SPEC_DATABASE__DatabaseStorage__getRow(&D_00585A30, id, self);
    self->cur = id;
    if (self->ref != -1 && func_0040EDE0(self, self->ref) == 0) {
        return 0;
    }
    return 1;
}
