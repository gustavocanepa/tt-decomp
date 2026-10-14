typedef unsigned char u8;
extern "C" int func_004114D0(void *self, unsigned v, u8 *out);

extern "C" u8 func_00411400(void *self, u8 *buf, u8 *out) {
    int bit = 0;
    int i = 0;
    u8 n = *buf++;
    if (n != 0) {
        do {
            u8 *o = out + i;
            int off = bit / 8;
            unsigned b1 = buf[off+1];
            unsigned b3 = buf[off+3];
            unsigned b2 = buf[off+2];
            unsigned b0 = buf[off];
            unsigned x = b0 + (b3 << 24);
            unsigned y = (b2 << 16) + (b1 << 8);
            unsigned v = (x + y) >> (bit - off * 8);
            bit += func_004114D0(self, v, o);
            i++;
        } while (i < n);
    }
    return n;
}
