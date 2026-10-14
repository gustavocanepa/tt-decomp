/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned char D_00586398[];
extern "C" void func_00434408(int, int *, int *) throw();
extern "C" int func_00434748(char *self) {
    int start;
    int end;
    int sum = 0;
    int i = 0;
    int weight = 0;
    do {
        func_00434408(i, &start, &end);
        int count = start;
        if (count < end) {
            int offset = (count << 1) + (i << 4);
            count = end - count;
            unsigned char factor = D_00586398[i];
            unsigned short *p = (unsigned short *)(offset + (int)self + 0x100);
            do {
                unsigned int value = *p++;
                --count;
                weight += factor << 8;
                sum += (value <= 256 ? value : 256) * factor;
            } while (count != 0);
        }
        ++i;
    } while (i < 8);
    sum = sum * 1000 / weight;
    int extra = *(unsigned short *)(self + 0x170) * 1000 / 59160;
    sum = (sum * 35 + extra * 15) * 2 / 100;
    if (sum > 1000) sum = 1000;
    return sum / 10;
}
