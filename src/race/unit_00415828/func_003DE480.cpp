/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_004EE530(float);
extern "C" int func_003DE480(float *x, float *y, float h, float a, float b) {
    float r = h * h;
    float a2 = a * a;
    float b2 = b * b;
    float sum = a2 + b2;
    if (sum <= r) {
        return 0;
    }
    float len;
    __asm__("sqrt.s %0, %1" : "=f"(len) : "f"(sum));
    *y = 1.570796294965744f - func_004EE530(h / len);
    float c = *y;
    if (a < 0.0f) {
        c = -(1.570796294965744f - func_004EE530(b / len));
    } else {
        c = 1.570796294965744f - func_004EE530(b / len);
    }
    *x = c;
    return 1;
}
