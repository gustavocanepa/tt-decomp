#include "types.h"

extern "C" void func_001D7C18(s32 *arg0);
extern "C" void func_002A7578(s32 *arg0, s32 *arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_002A75A8(s32 *arg0, s32 arg1);
extern "C" void func_001D7BC0(s32 *arg0, s32 arg1);

extern "C" void func_001D7F08(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 temp;
    s32 *ptemp = &temp;
    s32 newVal;
    s32 oldVal;

    func_001D7C18(p1);
    temp = *(s32 *)((char *)*p1 + 0x44);
    func_002A7578(buf0, ptemp);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_002A75A8(buf0, 2);
    func_001D7BC0(p1, 2);
}
