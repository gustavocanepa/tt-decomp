extern "C" void *func_004F64C4(void *, void *, int);
extern "C" void func_00458068(unsigned char *dst, int stride, int w, int h)
{
    unsigned char *p = dst;
    if (w > 0) {
        if (h > 0) {
            for (int i = w; i > 0; i--) {
                *p++ = 0;
                *p++ = 0;
                *p++ = 0;
            }
            int rows = h - 1;
            unsigned char *n = dst + stride * 3;
            p = dst;
            dst = n;
            for (; rows > 0; rows--) {
                unsigned char *d = dst;
                dst += stride * 3;
                func_004F64C4(d, p, w * 3);
            }
        }
    }
}
