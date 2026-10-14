typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef unsigned char u8;

struct func_002CBA00_arg1 {
    char pad0[4];
    u8 *out;
    char pad8[8];
    s32 w;
    s32 h;
};

struct func_002CBA00_arg2 {
    char pad0[4];
    u8 *in;
};

extern "C" void func_002CBA00(void *arg0, struct func_002CBA00_arg1 *arg1, struct func_002CBA00_arg2 *arg2) {
    u32 n;
    u32 i;
    u8 *p;
    u8 *o;
    s32 v;
    f32 sum;

    i = 0;
    p = arg2->in;
    n = (u32)(arg1->w * arg1->h);
    o = arg1->out;
    if (n != 0) {
        do {
            i += 1;
            sum = (f32)p[0] * 0x1.322D0Ep-2f;
            sum = sum + (f32)p[1] * 0x1.2C8B42p-1f;
            sum = sum + (f32)p[2] * 0x1.D2F1A8p-4f;
            p += 3;
            v = (s32)sum;
            if (v >= 0x100) {
                v = 0xFF;
            }
            *o = (u8)v;
            o += 1;
        } while (i < n);
    }
}
