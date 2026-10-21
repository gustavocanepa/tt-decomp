#include "types.h"
extern "C" s32 func_0046AE00(void);
extern "C" void ModelSet2__registerExternalTexSet(s32, s32);
extern "C" void func_0041A170(float);
extern "C" void func_00421C40(s32);
extern "C" void func_00421CE0(float);
extern "C" void func_00421CD0(float);
extern "C" void func_00478C98(s32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_0046F498(s32);
extern "C" void func_0046F470(s32);
extern "C" void func_004752F8(void *);
extern "C" void func_00475638(float, float, float);
extern "C" void func_00473050(void);
extern "C" void func_004757FC(void);
extern "C" void func_0047551C(void *);
extern "C" void func_004758C0(void *);
extern "C" void func_004730A8(void);
extern "C" void func_0017A880(s32 enabled) {
    char temporary[0x40];
    ModelSet2__registerExternalTexSet(0, func_0046AE00());
    func_0041A170(1.0f);
    func_00421C40(0);
    func_00421CE0(1.3f);
    func_00421CD0(1.1f);
    func_00478C98(8);
    func_0046F0F8(15);
    func_0046F498(0);
    func_0046F470(2);
    if (enabled != 0) {
        func_0046F498(1);
        func_0046F0F8(21);
        func_004752F8(temporary);
        func_00475638(1.0f, -1.0f, 1.0f);
        func_00473050();
        func_004757FC();
        func_0047551C(temporary);
        func_004752F8(temporary);
        func_004758C0(temporary);
        func_004730A8();
    }
}
