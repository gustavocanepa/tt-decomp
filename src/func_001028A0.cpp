typedef int s32;
typedef unsigned char u8;
typedef signed char s8;

static inline s32 avg3(u8 *p) {
    s32 x = p[0];
    s32 y = p[1];
    s32 z = p[2];
    s32 x3 = x + (x << 1);
    s32 y4 = (y << 2) + z;
    s32 sum = y4 + x3;
    return sum >> 3;
}

extern "C" void func_001028A0(void *arg0, void *arg1) {
    s8 *t9 = (s8 *)arg0;
    u8 *t8 = (u8 *)arg1;
    s32 s4 = 7;

    do {
        u8 *a2 = t8 + 0x3;
        u8 *a3 = t8 + 0x6;
        u8 *t0 = t8 + 0x9;
        u8 *t1 = t8 + 0xC;
        u8 *t2 = t8 + 0xF;
        u8 *t3 = t8 + 0x12;
        u8 *t4 = t8 + 0x15;
        u8 *t5 = t8 + 0x18;
        u8 *t6 = t8 + 0x1B;
        u8 *t7 = t8 + 0x1E;

        t9[0x00] = (s8)avg3(t8);
        t9[0x04] = (s8)avg3(a2);
        t9[0x08] = (s8)avg3(a3);
        t9[0x0C] = (s8)avg3(t0);
        t9[0x10] = (s8)avg3(t1);
        t9[0x14] = (s8)avg3(t2);
        t9[0x18] = (s8)avg3(t3);
        t9[0x1C] = (s8)avg3(t4);
        t9[0x02] = (s8)avg3(t5);
        t9[0x06] = (s8)avg3(t6);
        t9[0x0A] = (s8)avg3(t7);

        u8 *a2b = t8 + 0x21;
        t9[0x0E] = (s8)avg3(a2b);

        u8 *s0 = t8 + 0x24;
        u8 *s1 = t8 + 0x27;
        u8 *s2 = t8 + 0x2A;
        u8 *s3 = t8 + 0x2D;

        t9[0x12] = (s8)avg3(s0);
        t9[0x16] = (s8)avg3(s1);
        t9[0x1A] = (s8)avg3(s2);
        t9[0x1E] = (s8)avg3(s3);

        t8 += 0x30;
        t9 += 0x20;
        s4 -= 1;
    } while (s4 >= 0);
}
