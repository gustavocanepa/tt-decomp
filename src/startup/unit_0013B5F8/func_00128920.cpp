#include "types.h"

extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" void func_00128418(void *arg0, int arg1);
extern "C" s32 func_00132418(void *self);

extern "C" s32 func_00128920(void *arg0, void *arg1) {
    s32 a[4];
    s32 b[4];
    s32 *pb;
    s32 x;
    s32 y;
    s32 res;

    func_00128470(a, arg0);
    x = func_00132418((void *)a[0]);
    pb = b;
    func_00128470(pb, arg1);
    y = func_00132418((void *)pb[0]);
    res = x < y;
    func_00128418(pb, 2);
    func_00128418(a, 2);
    return res;
}
