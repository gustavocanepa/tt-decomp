/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Time { unsigned char h, m, s, pad; };
extern "C" Time func_004AF828(int seconds) {
    Time t;
    t.h = seconds / 3600;
    seconds %= 3600;
    t.m = seconds / 60;
    t.s = seconds % 60;
    return t;
}
