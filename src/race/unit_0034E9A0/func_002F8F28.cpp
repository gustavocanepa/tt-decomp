#include "types.h"

extern "C" void func_002F8F28(s32 n, s16 *in, s16 *out, s16 *out2) {
    s32 x1 = in[1];
    s32 i = 1;
    s32 go = i < n;

    out2[1] = (s16)((x1 * 9) / 8);
    if (go) {
        do {
            out[i] = (s16)((in[i] * 2 + in[i + 1]) / 3);
            out2[i + 1] = (s16)((in[i] + in[i + 1] * 2) / 3);
            i++;
        } while (i < n);
    }
    out[n] = (s16)((in[n] * 7) / 8);
    out[0] = (s16)((in[0] * 7) / 8);
    out2[0] = (s16)((in[0] * 9) / 8);
}
