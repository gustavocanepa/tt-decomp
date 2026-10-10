#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0036F848_arg0 {
    char pad0[0xDB8];
    f32 unkDB8;
    f32 unkDBC;
    f32 unkDC0;
    f32 unkDC4;
    f32 unkDC8;
    f32 unkDCC;
    f32 unkDD0;
};

void func_0036F848(struct func_0036F848_arg0 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6) {
    arg0->unkDB8 = fparg0;
    arg0->unkDBC = fparg1;
    arg0->unkDC0 = fparg2;
    arg0->unkDC4 = fparg3;
    arg0->unkDC8 = fparg4;
    arg0->unkDCC = fparg5;
    arg0->unkDD0 = fparg6;
}
