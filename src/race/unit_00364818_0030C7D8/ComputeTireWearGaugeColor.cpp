typedef int s32;
typedef signed char s8;

extern "C" void ComputeTireWearGaugeColor(s32 arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    s32 t;

    if (arg0 >= 0x40) {
        *arg1 = -4;
        *arg2 = (0x7F - arg0) * 2;
        *arg3 = 0;
        return;
    }
    if (arg0 >= 0x20) {
        *arg1 = -4;
        *arg2 = (0x5F - arg0) * 4;
        *arg3 = 0;
        return;
    }
    if (arg0 >= 0) {
        *arg1 = arg0 * 8;
        *arg2 = -4;
        *arg3 = 0;
        return;
    }
    if (arg0 >= -0x3F) {
        t = (-arg0) << 2;
        *arg1 = 0;
        *arg2 = -4 - t;
        *arg3 = t;
        return;
    }
    *arg3 = 0;
    *arg2 = 0;
    *arg1 = 0;
}
