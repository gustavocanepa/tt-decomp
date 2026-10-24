/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;

struct Req { u32 buf; u32 len; };
struct FIO {
    char pad0[0x18];
    char sub[0xD0];
    u32 f_E8;
    u32 buf;
    u32 avail;
    u32 pos;
};

extern "C" u32 func_0047F1D8(void *sub, Req *r);
extern "C" int func_004F64C4(void *dst, const void *src, u32 n);

extern "C" int hFileIO__read(FIO *self, char *dst, u32 n) {
    int total = 0;
    while (n != 0) {
        u32 pos = self->pos;
        u32 avail = self->avail;
        if (pos >= avail) {
            Req r;
            r.buf = self->buf;
            r.len = 0x800;
            u32 t = func_0047F1D8(self->sub, &r);
            self->avail = t;
            avail = t;
            self->pos = 0;
            pos = 0;
        }
        u32 cnt = (avail < pos + n) ? avail - pos : n;
        if (cnt != 0) {
            char *d = dst;
            n -= cnt;
            dst += cnt;
            func_004F64C4(d, (char *)self->buf + pos, cnt);
            self->pos += cnt;
            total += cnt;
        } else {
            if (avail < 0x800) {
                self->f_E8 = 1;
                break;
            }
        }
    }
    return total;
}
