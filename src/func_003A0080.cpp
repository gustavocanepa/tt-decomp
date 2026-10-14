/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
extern "C" u8 D_00583868[];
extern "C" float D_00584B98, D_00584B9C, D_00584BA0, D_00584BA4, D_00584BA8;
extern "C" void func_003A0080(void) {
    u8 a = D_00583868[0];
    float fa = a;
    D_00584B98 = fa * 0x1.999998p-4f;
    if (a != 0) {
        D_00584B9C = D_00583868[1] / fa;
        D_00584BA0 = D_00583868[2] / fa;
    } else {
        D_00584B9C = 0.0f;
        D_00584BA0 = 0.0f;
    }
    if (D_00583868[5] != 0)
        D_00584BA4 = 10.0f / D_00583868[5];
    else
        D_00584BA4 = 1.0f;
    if (D_00583868[6] != 0)
        D_00584BA8 = 10.0f / D_00583868[6];
    else
        D_00584BA8 = 0.25f;
}
