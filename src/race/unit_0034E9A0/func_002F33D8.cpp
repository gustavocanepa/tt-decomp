#include "types.h"
struct In {
    char pad[0x113];
    u8 b113, b114, b115, b116, b117, b118, b119, b11A, b11B;
};
struct Out {
    char pad[0xD4];
    s16 s_d4, s_d6;
    u8 b_d8, b_d9;
    char pad2[0xE4 - 0xDA];
    float f_e4, f_e8, f_ec, f_f0, f_f4, f_f8, f_fc;
};

static inline float scaled(float value, float scale) { return value * scale; }

extern "C" void func_002F33D8(In *a, Out *o) {
    float factor = 0.1f;
    if (a->b113 == 0) {
        o->f_fc = 0.0f;
    } else {
        o->f_fc = scaled(a->b113, factor);
        if (a->b116 == 0 || a->b118 == 0 || a->b11A == 0) o->f_fc = 0.0f;
    }
    if (o->f_fc == 0.0f) {
        o->f_f8 = 0.0f;
        o->s_d6 = 0;
        o->b_d8 = 0;
        o->f_e4 = 0.0f;
        o->f_ec = 0.0f;
        o->f_f4 = 0.0f;
        o->s_d4 = 0;
        do { o->b_d9 = 0; } while (0);
        o->f_e8 = 0.0f;
        o->f_f0 = 0.0f;
    } else {
        o->b_d8 = a->b114;
        if (o->b_d8 >= 3U) o->b_d8 = 0;
        float t1 = a->b118 * 0.1f;
        o->f_e4 = t1;
        o->f_ec = a->b11A * 0.1f;
        u8 v = a->b116;
        o->b_d9 = 0;
        o->f_e8 = 0.0f;
        o->f_f0 = 0.0f;
        o->f_f8 = 0.0f;
        o->s_d6 = 0;
        o->s_d4 = v * 100;
        float f0 = (s16)(v * 100);
        o->f_f4 = t1 / (f0 * f0);
        u8 a2 = a->b119;
        u8 a3 = a->b11B;
        u8 v3 = a->b117;
        if ((a2 + a3 + v3) != 0 && a2 != 0 && v3 != 0 && a3 != 0) {
            o->b_d9 = a->b115;
            if (o->b_d9 >= 3U) o->b_d9 = 0;
            float t2 = a->b119 * 0.1f;
            o->f_e8 = t2;
            o->f_f0 = a->b11B * 0.1f;
            u8 v5 = a->b117;
            o->s_d6 = v5 * 100;
            float f2 = (s16)(v5 * 100);
            o->f_f8 = t2 / (f2 * f2);
        }
    }
}
