#include "types.h"

extern char D_0076A028[];

extern "C" void func_004A4D68(void *);
extern "C" void func_004A4DD8(void *);
extern "C" void func_0042C320(s32);
extern "C" void func_0042C490(void);

extern "C" void func_0042C978(void) {
    func_004A4D68(D_0076A028);
    func_0042C320(1);
    func_0042C490();
    func_004A4DD8(D_0076A028);
}
