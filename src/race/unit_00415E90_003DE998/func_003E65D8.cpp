#include "types.h"

extern "C" void func_003E6388(void *arg0, float *arg1);

extern "C" void *func_003E65D8(void *arg0, float *arg1) {
    float buf[9];
    buf[0] = arg1[0];
    buf[3] = arg1[4];
    buf[6] = arg1[8];
    buf[1] = arg1[1];
    buf[4] = arg1[5];
    buf[7] = arg1[9];
    buf[2] = arg1[2];
    buf[5] = arg1[6];
    buf[8] = arg1[10];
    func_003E6388(arg0, buf);
    return arg0;
}
