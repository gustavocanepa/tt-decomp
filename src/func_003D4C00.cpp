/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

extern "C" void func_003D4C00(s32 type, s32 a1, s32 a2, s32 a3, s32 n, f32 *out1, f32 *out2) {
    switch (type) {
    case 4:
        *out1 = 0.0f;
        if (n > 0) {
            *out2 = -1.0f;
        } else {
            *out2 = 1.0f;
        }
        return;
    case 1:
        if (n >= a3) {
            n = a3;
        }
        if (n <= 0) {
            n = a2;
        } else {
            n = n + a1 - 1;
        }
        if (n > 0) {
            *out1 = (f32)((n - 1) / 2 - 1) * 0.5f;
            if ((n & 1) == 0) {
                *out2 = -1.0f;
            } else {
                *out2 = 1.0f;
            }
        } else {
            *out1 = (f32)(n / 2 - 2) * 0.5f;
            if ((n & 1) == 0) {
                *out2 = -1.0f;
            } else {
                *out2 = 1.0f;
            }
        }
        return;
    case 2:
    case 3:
    default:
        *out1 = 0.0f;
        *out2 = 0.0f;
        return;
    }
}
