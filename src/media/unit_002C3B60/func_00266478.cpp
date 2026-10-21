#include "types.h"
struct Obj {
    char pad[0x14];
    s32 f14;
};
extern "C" void func_004B5F48(s32 *a, s32 *b, s32 *c);
extern "C" s32 func_00266478(Obj *o) {
    s32 v[3];
    if (o->f14 == 0) return 0;
    func_004B5F48(&v[0], &v[1], &v[2]);
    return v[2] == 0;
}
