typedef int s32;
typedef float f32;
typedef unsigned char u8;

extern "C" void func_002DED58(void *a0);
extern "C" void func_002DF380(void *a0, s32 a1, void *a2);

extern "C" void func_002DF288(char *arg0, char *arg1, s32 arg2) {
    char *p = arg1;
    f32 best = 0.0f;
    s32 bestIdx = -1;
    s32 i = 0;
    if (arg2 > 0) {
        do {
            f32 x = *(f32 *)p;
            f32 z = *(f32 *)(arg0 + 0x38);
            f32 y = *(f32 *)(arg0 + 0x34);
            f32 s = *(f32 *)(arg0 + 0x40);
            f32 w = *(f32 *)(arg0 + 0x3C);
            f32 v7 = *(f32 *)(p + 4);
            f32 v4 = *(f32 *)(p + 8);
            f32 t = x * y + v7 * z + v4 * w + s;
            p += 12;
            if (t < 0.0f) {
                f32 d = -(x * y + v4 * w + s) / z - v7;
                if (best < d) {
                    best = d;
                    bestIdx = i;
                    ((u8 *)arg0)[0x58 + i] = ((u8 *)arg0)[0x58 + i] + 1;
                }
            } else {
                ((u8 *)arg0)[0x58 + i] = 0;
            }
            i++;
        } while (i < arg2);
    }
    *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x14) + best;
    if (bestIdx >= 0) {
        func_002DF380(arg0, bestIdx, (void *)((char *)arg0 + 0x34));
    }
    func_002DED58(arg0);
}
