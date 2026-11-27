#include "types.h"

struct Value {
    s32 type;
    s32 data[3];
};

extern "C" void func_0043DE58(Value *, s32);
extern "C" void func_0043D3B8(Value *, Value *);
extern "C" void func_0043D510(Value *);

extern "C" Value *func_00447788(Value *ret, s32 arg) {
    Value t;
    t.type = 1;
    func_0043DE58(&t, arg);
    func_0043D3B8(ret, &t);
    func_0043D510(&t);
    return ret;
}
