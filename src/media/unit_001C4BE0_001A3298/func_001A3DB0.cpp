/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_001A3D58(short *p, short *end) throw();
extern "C" void *func_004F64C4(void *, const void *, unsigned) throw();
extern "C" int func_001A3DB0(int *dst, short *src) {
    short *end = (short *)((char *)src + 0x8000);
    int more = src < end;
    short *out = (short *)(dst + 1);
    int lit = 0;
    int state = 0;
    unsigned short v;
    short *o;
    if (more) {
        do {
            int n = func_001A3D58(src, end);
            if (state == 0) {
                if (n < 2) {
                    src++;
                    lit = n;
                    state = 1;
                    more = src < end;
                } else {
                    *out++ = n;
                    v = *src;
                    src = (short *)((char *)src + n * 2);
                    more = src < end;
                    *out++ = v;
                }
            } else if (state == 1) {
                if (n >= 4 || (n == 3 && func_001A3D58(src + 3, end) >= 2)) {
                    int bytes = lit * 2;
                    *out++ = -lit;
                    o = out;
                    func_004F64C4(o, (char *)src - bytes, bytes);
                    out = (short *)((char *)out + bytes);
                    state = 0;
                    *out++ = n;
                    v = *src;
                    src = (short *)((char *)src + n * 2);
                    lit = 0;
                    more = src < end;
                    *out++ = v;
                } else {
                    src++;
                    lit++;
                    more = src < end;
                }
            }
        } while (more);
    }
    if (lit != 0) {
        int bytes = lit * 2;
        *out++ = -lit;
        o = out;
        func_004F64C4(o, (char *)src - bytes, bytes);
        out = (short *)((char *)out + bytes);
    }
    int size = (char *)out - (char *)dst;
    *dst = size - 4;
    return size;
}
