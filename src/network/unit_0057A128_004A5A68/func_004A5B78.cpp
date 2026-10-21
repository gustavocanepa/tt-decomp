/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" float func_004A5A68(float) throw();

extern "C" float func_004A5B78(float y, float x) {
    register float r;
    int f = 0;
    if (x == 0.0f && y == 0.0f) return 0.0f;
    if (y < 0.0f) { y = -y; f = 4; }
    if (x < 0.0f) { x = -x; f |= 2; }
    if (y < x) {
        r = y / x;
    } else {
        f |= 1;
        r = x / y;
    }
    r = func_004A5A68(r);
    float halfpi = 0x1.921fb4p+0f;
    if (f & 1) r = halfpi - r;
    halfpi = 0x1.921fb4p+1f;
    if (f & 2) r = halfpi - r;
    if (f & 4) r = -r;
    return r;
}
