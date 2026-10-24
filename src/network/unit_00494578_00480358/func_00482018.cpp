extern "C" unsigned short *func_00482018(unsigned short *base, int limit, int count)
{
    unsigned short *p = base;
    int k = 0;
    int i = 0;
    if (count > 0) {
        do {
            unsigned short *q = p + i;
            int n = 0;
            if (*q != 0) {
                do {
                    q++;
                    n++;
                } while (*q != 0);
            }
            i = i + n + 1;
            if (i >= limit) {
                return 0;
            }
            k++;
        } while (k < count);
    }
    return p + i;
}
