#include "types.h"

extern "C" float func_004B2B08(float f);

extern "C" void func_00177148(s32 base, s32 limit, s32 *out, s32 count, s32 exclude) {
    s32 i;
    s32 n;
    s32 remaining;
    s32 range;
    s32 *p;
    for (i = 0; i < count; i++) {
        out[i] = -1;
    }
    n = 0;
    remaining = limit - base;
    range = remaining;
    if (n < count) {
        p = out;
        do {
            s32 v;
            if (remaining <= 0) {
                break;
            }
            if (exclude >= 0 && remaining < 2) {
                break;
            }
            v = (s32)func_004B2B08((float)range) + base;
            if (v != exclude) {
                s32 found = 0;
                s32 j;
                for (j = 0; j < n; j++) {
                    if (out[j] == v) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    n++;
                    *p = v;
                    remaining--;
                    p++;
                }
            }
        } while (n < count);
    }
}
