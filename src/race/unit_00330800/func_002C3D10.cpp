/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { int unk0; char *data; int unk8, unkC; int width, height, depth, unk1C, size; };
extern "C" void func_002C3D10(Image *p, int x, int z) {
    int top = 0;
    int bottom = p->height - 1;
    unsigned int count = (unsigned int)(p->width * p->size) >> 3;
    while (top < bottom) {
        int height = p->height;
        int stride = p->width * p->size;
        char *base = p->data + stride * height * (z * p->depth + x);
        long *a = (long *)(base + stride * top);
        long *b = (long *)(stride * bottom + base);
        if (count != 0) {
          unsigned int n = count;
          do {
            long *pa = a++;
            long *pb = b++;
            long t = *pa;
            --n;
            *pa = *pb;
            *pb = t;
          } while (n != 0);
        }
        ++top;
        --bottom;
    }
}
