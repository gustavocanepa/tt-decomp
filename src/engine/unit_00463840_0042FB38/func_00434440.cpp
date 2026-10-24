/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
extern "C" void func_004343D0(int, int *, int *) throw();
extern u8 D_00586398[];

extern "C" int func_00434440(char *obj) {
    int bounds[2];
    int i = 0;
    int total = 0;
    do {
        func_004343D0(i, &bounds[0], &bounds[1]);
        int sum = 0;
        int denom = 0;
        int n = bounds[0];
        int end = bounds[1];
        if (n < end) {
            char *p = (char *)((n * 8 + i) * 2 + (int)obj);
            do {
                u16 a = *(u16 *)p;
                int ca = a < 0x401U ? a : 0x400U;
                int weight = D_00586398[n];
                u16 b = *(u16 *)(p + 0x80);
                p += 0x10;
                int step = weight << 10;
                n++;
                denom += step;
                denom += step;
                sum = ca * weight + sum;
                ca = b < 0x401U ? b : 0x400U;
                sum += ca * weight;
            } while (n < end);
        }
        i++;
        total += sum * 125 / denom;
    } while (i < 8);
    if (total > 1000) total = 1000;
    return total / 10;
}
