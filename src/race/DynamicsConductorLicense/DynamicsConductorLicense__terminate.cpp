#include "types.h"

struct Obj_003F5FF0 {
    char pad0[0x241CC];
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual s32 v06();
};

extern "C" void func_002F3028(Obj_003F5FF0 *o);
extern "C" void func_002FBF80(Obj_003F5FF0 *o);

extern "C" void DynamicsConductorLicense__terminate(Obj_003F5FF0 *o) {
    func_002F3028(o);
    if (o->v06()) {
        return func_002FBF80(o);
    }
}
