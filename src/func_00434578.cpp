/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00434408(int, int *, int *) throw();
extern unsigned char D_00586398[];
extern "C" int func_00434578(char *obj) {
    int bounds[2];
    int i = 0;
    int total = 0;
    int offset = 0;
    do {
        func_00434408(i, &bounds[0], &bounds[1]);
        int sum = 0;
        int denom = 0;
        int n = bounds[0];
        if (n < bounds[1]) {
            unsigned char weight = D_00586398[i];
            char *p = (char *)((offset + n) * 2 + (int)obj);
            n = bounds[1] - n;
            do {
                unsigned short a = *(unsigned short *)p;
                unsigned short b = *(unsigned short *)(p + 0x80);
                p += 2;
                int clipped;
                clipped = a < 0x401U ? a : 0x400U;
                int step = weight << 10;
                denom += step;
                sum = clipped * weight + sum;
                clipped = b < 0x401U ? b : 0x400U;
                denom += step;
                sum += clipped * weight;
                n--;
            } while (n != 0);
        }
        i++;
        offset += 8;
        total += sum * 125 / denom;
    } while (i < 8);
    total = (total * 70 + (*(unsigned short *)(obj + 0xF0) * 1000 / 59160) * 20 + (*(unsigned short *)(obj + 0x170) * 1000 / 59160) * 10) / 100;
    if (total > 1000) total = 1000;
    return total / 10;
}
