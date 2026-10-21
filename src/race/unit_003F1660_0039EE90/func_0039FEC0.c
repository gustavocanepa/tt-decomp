typedef int s32;
typedef unsigned char u8;
typedef float f32;
void func_0039FEC0(char *arg0, f32 fparg0) {
    char *a1 = *(char **)(arg0 + 0x10);
    char *a0 = arg0 + 0x104;
    s32 t = *(u8 *)(a1 + 0x10C3);
    if (t == 0) return;
    if (t >= 3) {
        if (t >= 7) return;
        if (t < 5) return;
    }
    *(f32 *)(a0 + 0x5CC) = *(f32 *)(a0 + 0x5CC) + (*(f32 *)(a1 + 0x10D0) * fparg0 * *(f32 *)(a0 + 0x5B4));
}
