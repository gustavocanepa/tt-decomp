#include "types.h"
#include "m2c_macros.h"
extern "C" void func_0020B408(void);
extern "C" void func_001C7410(s32);
extern "C" void func_004A5668(s32);
extern "C" void func_004A5880(s32);
extern "C" void free(s32);
extern "C" void func_00187DB0(void *self) {
    func_0020B408();
    M2C_FIELD(self, s32 *, 0xB8) = 1;
    func_001C7410(1);
    func_004A5668(M2C_FIELD(self, s32 *, 0xB4));
    func_004A5880(M2C_FIELD(self, s32 *, 0xB4));
    M2C_FIELD(self, s32 *, 0xB4) = 0;
    free(M2C_FIELD(self, s32 *, 0xCC));
    s32 *p = (s32 *)((char *)self + 0xC4);
    s32 count = 1;
    do {
        free(*p);
        p++;
        count--;
    } while (count >= 0);
}
