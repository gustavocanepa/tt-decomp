typedef float f32;
typedef int s32;
typedef unsigned char u8;

struct func_0039F8A0_p;

extern "C" f32 func_0039F8A0(struct func_0039F8A0_p *p, f32 x);

extern "C" void func_0039F8F0(char *arg0) {
    char *a2 = *(char **)(arg0 + 0x10);
    s32 a1 = *(u8 *)(a2 + 0x10C3);
    char *s0 = arg0 + 0x104;

    *(s32 *)(s0 + 0x5B4) = 0;
    *(s32 *)(s0 + 0x5B8) = 0;
    *(u8 *)(s0 + 0x5B2) = 0;
    *(u8 *)(s0 + 0x5B3) = 0;

    switch (a1) {
    case 1:
        if (*(f32 *)(a2 + 0x10C8) <= *(f32 *)(s0 + 0x55C)) {
            f32 v = 1.0f;
            *(u8 *)(s0 + 0x5B2) = (u8)a1;
            *(f32 *)(s0 + 0x5B4) = v;
        }
        break;
    case 2: {
        f32 r = func_0039F8A0((struct func_0039F8A0_p *)arg0, *(f32 *)(s0 + 0x55C));
        *(f32 *)(s0 + 0x5B4) = r;
        break;
    }
    case 6:
        if (*(f32 *)(a2 + 0x10C8) <= *(f32 *)(s0 + 0x55C)) {
            f32 v = 0x1.3B13B0p-3f;
            *(u8 *)(s0 + 0x5B2) = 1;
            *(f32 *)(s0 + 0x5B4) = v;
        }
        break;
    }
}
