typedef unsigned char u8;
typedef int s32;

extern "C" s32 func_004881A0(u8 *arg0) {
    u8 *a = arg0 + 0x14;
    u8 *b = arg0 + 0x1A;
    return ((a[1] << 8) | a[0]) << 16 | ((b[1] << 8) | b[0]);
}
