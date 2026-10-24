/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { int a; unsigned char *data; int b,c; int w,h,cols,rows,bpp; };
extern "C" void func_004F6678(void *, int, unsigned);
extern "C" void func_001A5928(Image **self, unsigned char *dst, int index) {
    if (index < 0 || index >= (*self)->w * (*self)->cols)
        return func_004F6678(dst, 255, (*self)->h * (*self)->rows * 3);
    int width = (*self)->w;
    index = width * (*self)->cols - index - 1;
    int y = index / width;
    index %= width;
    int stride = width * (*self)->bpp;
    int height = (*self)->h;
    int i = 0;
    if (i < (*self)->rows) do {
        int pitch = (*self)->w * (*self)->bpp;
        unsigned char *base = (*self)->data + pitch * (*self)->h * (i * (*self)->cols + y);
        unsigned char *src = (unsigned char *)(index * (*self)->bpp + (int)base);
        for (int j = 0; j < height; j++) {
            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            src += stride;
            dst += 3;
        }
        i++;
    } while (i < (*self)->rows);
}
