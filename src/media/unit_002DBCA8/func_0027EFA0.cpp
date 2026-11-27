#include "types.h"

extern "C" s32 func_00206DF8(s32 arg0);
extern "C" s32 func_0027EDF8(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0027EFA0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s2 = arg2;
    s32 s3 = arg3;
    for (;;) {
        if (s2 == s3) {
            return s2;
        }
        s32 n = 0;
        s32 p = s2;
        do {
            n += 1;
            p = func_00206DF8(p);
        } while (p != s3);
        s32 q = s2;
        if (n >= 2) {
            do {
                n -= 2;
                q = func_00206DF8(q);
            } while (n >= 2);
        }
        if (func_0027EDF8(arg0, arg1, q) != 0) {
            s3 = q;
            continue;
        }
        if (q == s2) {
            return s3;
        }
        s2 = q;
    }
}
