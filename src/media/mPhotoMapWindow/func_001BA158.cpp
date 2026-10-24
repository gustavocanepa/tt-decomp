#include "types.h"

struct Obj {
    char pad0[0xC0];
    s32 unk58;
};

struct S_0025C2E0;

extern "C" s32 func_0020D610(Obj *arg0);
extern "C" s32 func_00206DE8(S_0025C2E0 *arg0);

extern "C" s32 func_001BA158(Obj *arg0)
{
    s32 var_s0;

    var_s0 = arg0->unk58;
    if (var_s0 != 0)
    {
        do
        {
            if (func_0020D610((Obj *)var_s0) == 0)
            {
                return var_s0;
            }
            var_s0 = func_00206DE8((S_0025C2E0 *)var_s0);
        } while (var_s0 != 0);
    }
    return 0;
}
