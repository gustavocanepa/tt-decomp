typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef float f32;

extern "C" f32 func_002F0570(char *arg0);
extern "C" f32 func_002F0AD8(char *arg0, s32 arg1);

extern "C" s32 func_00300588(char *arg0) {
    s32 r = 0;
    char *s1 = arg0 + 0x104;
    char *s0 = *(char **)(arg0 + 0x4);
    u32 k = (u32)((*(u8 *)(s1 + 0x487) + 0xFE) & 0xFF);
    if (!(k < 3)) {
        return r;
    }
    f32 t = func_002F0570(s0);
    f32 f20 = *(f32 *)(s1 + 0x4C4);
    if (f20 < t * 0.5f) {
        f20 += t;
    }
    if (f20 < func_002F0AD8(s0, 1)) {
        return r;
    }
    if (func_002F0AD8(s0, -1) < f20) {
        return 0;
    }
    return 1;
}
