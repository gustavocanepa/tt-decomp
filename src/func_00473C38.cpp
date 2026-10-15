extern "C" float func_00473C38(int arg0, float arg1)
{
    float r;
    float b;
    float c;
    int n;
    int bits;
    int k;
    int sh;

    r = 1.0f;
    b = arg1;
    c = arg1;
    __asm__ __volatile__("sqrt.s %0, %1" : "=f"(c) : "f"(c));

    n = arg0 >> 16;
    bits = arg0;
    k = n - 4;
    if (k >= 0) {
        do {
            if (bits & 1) {
                r = r * b;
            }
            bits = bits >> 1;
            k -= 1;
            b = b * b;
        } while (k >= 0);
    }

    sh = 9 - n;
    bits = bits >> sh;
    k = 4;
    do {
        if (bits & 1) {
            r = r * c;
        }
        bits = bits >> 1;
        __asm__ __volatile__("sqrt.s %0, %1" : "=f"(c) : "f"(c));
        k -= 1;
    } while (k >= 0);

    return r;
}
