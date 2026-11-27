#include "types.h"

extern "C" void func_004A4D68(void *arg0);
extern "C" void func_004A4DD8(void *arg0);
extern "C" s32 func_004B87F8(s32 arg0, s32 arg1);

extern void *D_0059834C;

extern "C" s32 func_004B8DA8(s32 arg0, s32 arg1) {
    func_004A4D68((char *)D_0059834C + 0x34);
    s32 result = func_004B87F8(arg0, arg1);
    func_004A4DD8((char *)D_0059834C + 0x34);
    return result;
}
