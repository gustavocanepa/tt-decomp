/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
typedef unsigned short u16;
struct GzHeader {
    u16 magic;
    u8 method;
    u8 flags;
    u8 rest[8];
} __attribute__((packed));

int func_004D9B38(u8 *data, u8 **extra, u8 **name, u8 **comment, u16 *hcrc, u8 **end) {
    struct GzHeader h;
    u8 *p = data + 10;
    if (extra) *extra = 0;
    if (name) *name = 0;
    if (comment) *comment = 0;
    if (hcrc) *hcrc = 0;
    if (end) *end = 0;
    if (!data) return -1;
    h = *(struct GzHeader *)data;
    if (h.magic != 0x8B1F) return -1;
    if (h.flags & 4) {
        int xlen = data[10] | (p[1] << 8);
        if (extra) *extra = p;
        p += xlen;
    }
    if (h.flags & 8) {
        if (name) *name = p;
        { while (*p != 0) p++; p++; }
    }
    if (h.flags & 0x10) {
        if (comment) *comment = p;
        { while (*p != 0) p++; p++; }
    }
    if (h.flags & 2) {
        if (hcrc) *hcrc = p[0] | (p[1] << 8);
        p += 2;
    }
    if (end) *end = p;
    return 0;
}
