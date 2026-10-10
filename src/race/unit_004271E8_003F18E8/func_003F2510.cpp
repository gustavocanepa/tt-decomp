extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F3E68(...) throw();
s32 func_00468938(f32, f32, f32, f32, f32, f32, f32, f32, f32) throw();
s32 func_00473050(...) throw();
s32 func_004730A8(...) throw();
void func_004752F8(...) throw();

struct func_003F2510_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_003F2510(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7, f32 arg_sp0) {
    func_00473050();
    func_00468938(fparg0, fparg1, fparg2, fparg3, fparg4, fparg5, fparg6, fparg7, arg_sp0);
    func_004752F8(arg0 + 0x10);
    ((struct func_003F2510_arg0 *)arg0)->unkC = 1;
    func_004730A8();
    func_003F3E68(arg0);
}

}
