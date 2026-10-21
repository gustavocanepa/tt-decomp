/* compiler: ee-gcc2.9-991111 */
typedef unsigned long u64;
typedef long s64;
s64 func_004FC168(u64 m, int unused0) {
    s64 result;
    s64 e = (m << 1) >> 53;
    e -= 0x433;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    m = (m << 12) >> 12;
    m |= (u64)1 << 52;
    if (e < 0) {
        e = -e;
        m >>= (int)(e - 2);
        if ((m & 3) == 3) m = (m >> 2) + 1;
        else m >>= 2;
        result = m << 32;
    } else {
        m <<= (int)e;
        result = m << 32;
    }
    return result >> 32;
}
