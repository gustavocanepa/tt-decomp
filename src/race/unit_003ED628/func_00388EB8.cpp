#include "types.h"

extern "C" s32 func_00388C10(void);
extern "C" void func_004A45D0(s32 arg0);
extern "C" void func_00388C30(void *arg0);

extern char D_00584778[];
extern s32 D_00584774;

extern "C" void func_00388EB8(void) {
    func_004A45D0(func_00388C10());
    func_00388C30(D_00584778);
    D_00584774 = 0;
}
