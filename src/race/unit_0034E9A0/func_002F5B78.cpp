/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Config { unsigned char pad[6]; unsigned char en[2]; unsigned char a[2]; unsigned char b[2]; };
extern Config D_00583868;
extern "C" float func_002F5B78(int offset, float x) {
    float r = 1.0f;
    offset += 0xb0;
    if (D_00583868.en[offset]) {
        float b = D_00583868.b[offset] * 0x1.1c71c6p-2f;
        float a = D_00583868.a[offset] * 0x1.47ae14p-7f;
        float c = 1.0f - a;
        if (x < 0.0f) x = -x;
        if (x < b) r = a + c * x / b;
    }
    return r;
}
