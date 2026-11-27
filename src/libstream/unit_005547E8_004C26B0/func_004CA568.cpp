#include "types.h"

extern "C" void func_004A4D68(s32 arg0);
extern "C" void func_004A4DD8(s32 arg0);
extern "C" void func_004AC8B8(s32 arg0, s32 arg1);

extern "C" void func_004CA568(s32 arg0, s32 arg1) {
    func_004A4D68(arg0);
    func_004AC8B8(arg0 + 0x30, arg1 + 8);
    func_004A4DD8(arg0);
}
