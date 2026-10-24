#include "types.h"
extern "C" u8 *func_001CDAA0(u8 *);
extern "C" float func_004AFED0(float, float, float, float, float);
extern "C" void func_00260620(u8 *self) {
    int i = 0;
    float *dst = (float *)func_001CDAA0(self + 0xB4);
    for (; i < 3; i++) {
        float *src = (float *)(self + 0x350);
        float *p = dst + i;
        float *q = src + i;
        *p = func_004AFED0(*p, *q, 0x1.999998p-5f, -180.0f, 180.0f);
    }
}
