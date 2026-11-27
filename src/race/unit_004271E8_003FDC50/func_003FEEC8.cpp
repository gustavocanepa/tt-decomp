#include "types.h"

struct Obj_00438670 {
    char pad0[8];
    s32 m8;
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual s32 v12(s32 a, s32 b);
};

extern "C" s32 func_003FEB98(s32 a);

extern "C" s32 func_003FEEC8(Obj_00438670 *arg0, s32 arg1, s32 arg2) {
    return arg0->v12(func_003FEB98(arg0->m8), arg2);
}
