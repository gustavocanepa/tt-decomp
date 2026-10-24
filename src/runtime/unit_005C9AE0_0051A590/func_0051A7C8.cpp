#include "types.h"

extern "C" void func_0051A888(void *arg0, void *arg1, s32 arg2);

extern "C" long *func_0051A7C8(long *arg0, long *arg1, long *arg2, int unused0, int unused1) {
    if (arg0 == arg1) {
        return arg2;
    }
    if (arg2 == arg1) {
        return arg0;
    }
    func_0051A888(arg0, arg1, 0);
    func_0051A888(arg1, arg2, 0);
    if (arg1 != arg2) {
        do {
            long *a = arg0;
            long t;
            volatile long dummy;
            arg0 += 1;
            arg2 -= 1;
            t = *a;
            dummy = t;
            *a = *arg2;
            *arg2 = t;
            if (arg0 == arg1) {
                break;
            }
        } while (arg1 != arg2);
    }
    if (arg0 == arg1) {
        func_0051A888(arg1, arg2, 0);
        return arg2;
    } else {
        func_0051A888(arg0, arg1, 0);
        return arg0;
    }
}
