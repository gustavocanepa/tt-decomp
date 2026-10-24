/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Image { int f0; u8 *data; int f8, fC, width, height, cols, rows, channels; };
extern "C" void func_002C3F00(Image *img, int x, int y) {
    int n=img->width;
    if (n == img->height) {
        int rowbytes = n * img->channels;
        int c=img->channels;
        int skip = rowbytes - img->channels;
        for (int i = 1; i < img->width; ++i) {
            int size=img->width*img->channels;
            size*=img->height;
            u8 *base=img->data+size*(y*img->cols+x);
            u8 *q=base+i*(unsigned)c;
            u8 *p=i*rowbytes+base;
            for(int j=0; j<i; ++j) {
                for(int k=0; k<c; ++k) {
                    u8 *a=q++;
                    u8 *b=p++;
                    u8 t=*a;
                    *a=*b;
                    *b=t;
                }
                q+=skip;
            }
        }
    }
}
