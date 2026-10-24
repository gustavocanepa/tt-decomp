/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef long s64;
extern "C" int func_004BCE98(u8 *, int, s64 *, s64 *);

/* MPEG-2 PES packet header: checks the start code prefix and the video stream id (0xE0-0xEF),
   returns the payload and its length, and reads the PTS/DTS through func_004BCE98 when the
   header flags say they are present. One header byte variable is reused for each field func_005AE2E8. */
extern "C" int func_004BCD90(u8 *p, u8 **out, int *len, s64 *pts, s64 *dts) {
    unsigned int v;
    *len = 0;
    v = (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
    if ((v >> 8) != 1) return 1;
    if ((v & 0xF0) != 0xE0) return 1;
    int size = p[5] | (p[4] << 8);
    v = p[6];
    if ((v & 0xC0) != 0x80) return 1;
    u8 headerLen = p[8];
    int flags = p[7] >> 6;
    *len = size - headerLen - 3;
    *out = p + headerLen + 9;
    *dts = -1;
    *pts = -1;
    switch (flags) {
    case 0:
        break;
    case 2:
        if (func_004BCE98(p, 9, pts, dts) != 0) return 1;
        break;
    case 3:
        if (func_004BCE98(p, 9, pts, dts) != 0) return 1;
        break;
    default:
        return 1;
    }
    return 0;
}
