/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline const int &imax(const int &a, const int &b) { return a < b ? b : a; }
static inline const int &imin(const int &a, const int &b) { return b < a ? b : a; }
extern "C" void func_00444A78(unsigned char *out, int r, int g, int b, int a) {
    out[0] = imin(255, imax(0, r));
    out[1] = imin(255, imax(0, g));
    out[2] = imin(255, imax(0, b));
    out[3] = imin(255, imax(0, a));
}
