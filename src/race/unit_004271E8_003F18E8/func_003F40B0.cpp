/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

extern "C" void func_003F40B0(char *arg0)
{
    char *b = arg0 + (*(s32 *)(arg0 + 0x8) << 6);
    f32 *s = (f32 *)(b + 0xC);
    f32 *d = (f32 *)(b + 0x4C);

    d[0] = s[0];
    d[4] = s[4];
    d[8] = s[8];
    d[12] = s[12];
    d[1] = s[1];
    d[5] = s[5];
    d[9] = s[9];
    d[13] = s[13];
    d[2] = s[2];
    d[6] = s[6];
    d[10] = s[10];
    d[14] = s[14];
    d[3] = s[3];
    d[7] = s[7];
    d[11] = s[11];
    d[15] = s[15];

    *(s32 *)(arg0 + 0x8) += 1;
}
