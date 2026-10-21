extern "C" float func_003A8C68(float lo, float hi, float p, float x)
{
    if (lo <= x && x <= hi) return x;
    if (hi <= lo) {
        return x;
    }
    int n = 0x100;
    if (x < lo) {
        while (x < lo) {
            n--;
            x += p;
            if (n < 0) x = lo + 1.0f;
        }
    } else {
        while (lo < x) {
            n--;
            x -= p;
            if (n < 0) x = lo - 1.0f;
        }
        x += p;
    }
    if (lo <= x && x <= hi) return x;
    if (lo < x) {
        n = 0x100;
        do {
            n--;
            x -= p;
            if (n < 0) x = lo - 1.0f;
        } while (lo < x);
    }
    float r = x;
    lo -= x;
    n = 0x100;
    while (x < hi) {
        n--;
        x += p;
        if (n < 0) x = hi + 1.0f;
    }
    if (lo < x - hi) return r;
    return x;
}
