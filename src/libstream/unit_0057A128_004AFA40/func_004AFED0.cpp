extern "C" float func_004AFC98(int, float, float) throw() __attribute__((const));
extern "C" float func_004AFED0(float a, float b, float t, float lo, float hi) {
    float result = a;
    b = b - result;
    b = func_004AFC98(1, b - lo, hi - lo) + lo;
    b *= t;
    result += b;
    return result;
}
