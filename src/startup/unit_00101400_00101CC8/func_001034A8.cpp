#include "types.h"

struct Key {
    s32 a;
    s32 b;
    Key(s32 x, s32 y) : a(x), b(y) {}
};

struct Result {
    s32 err;
    s32 pad[3];
    s32 value;
    s32 pad2[3];
    Result();
    Result(const Result &);
};

extern "C" const char *func_00455930(s32);
extern "C" void *func_00103248(void *str, const char *name);
extern "C" Result func_0047DC60(void *, Key *, s32);
extern "C" void func_00466B28(s32);

extern s32 D_0057930C;
extern s32 D_00579310;
extern s32 D_00579314;

extern "C" void func_001034A8(s32 arg0)
{
    char path[0x80];

    D_0057930C = 0;
    if (D_00579310 == 0) {
        return;
    }
    func_00103248(path, func_00455930(arg0));
    Key key(D_00579314, D_00579310);
    const Result &res = func_0047DC60(path, &key, 1);
    if (res.err == 0) {
        D_0057930C = res.value;
        func_00466B28(res.value);
    }
}
