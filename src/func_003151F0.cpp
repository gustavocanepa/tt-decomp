extern "C" float func_00315180(float a);

extern "C" float func_003151F0(float x) {
    float r;

    r = x;
    if (x < -0x1.921FB4p+1f) {
        if (x < -0x1.2D97C6p+3f) {
            return func_00315180(x);
        }
        r = x + 0x1.921FB4p+2f;
    } else if (x >= 0x1.921FB4p+1f) {
        if (x > 0x1.2D97C6p+3f) {
            return func_00315180(x);
        }
        r = x - 0x1.921FB4p+2f;
    }
    return r;
}
