extern "C" unsigned int func_00462728(const unsigned char *p, unsigned int len) {
    const unsigned char *end = p + len;
    unsigned int h = 0;
    while (p < end) {
        h = (h << 4) + *p++;
        unsigned int g = h & 0xF0000000;
        if (g) {
            h ^= g >> 24;
        }
        h &= ~g;
    }
    return h;
}
