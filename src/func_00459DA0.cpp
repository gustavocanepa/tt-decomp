/* compiler: ee-gcc2.96-no-strict-aliasing */
struct BS {
    int pad0, pad4;
    int pos;
    int cnt;
    unsigned char *ptr;
    int pad14;
    int flag;
};
extern int D_00586A80[];
extern "C" int func_00459DA0(BS *s, int n, int *marker) {
    unsigned acc;
    int mask = D_00586A80[n];
    if (s->cnt < 0) {
        s->pos++;
        s->ptr++;
        s->cnt = 7;
        if (s->flag == 0) {
            s->pos++;
            s->ptr++;
            s->flag = 1;
        }
        if (s->ptr[0] == 0xFF) {
            if (s->ptr[1] == 0) { s->flag = 0; }
            else { ret: *marker = 1; return 0xFF00 + s->ptr[1]; }
        }
    }
    n = n - s->cnt - 1;
    acc = *s->ptr;
    while (n > 0) {
        s->pos++;
        s->ptr++;
        if (s->flag == 0) {
            s->pos++;
            s->ptr++;
            s->flag = 1;
        }
        unsigned char *q = s->ptr;
        acc = (acc << 8) | *q;
        if (*q == 0xFF) {
            if (q[1] == 0) { s->flag = 0; }
            else { goto ret; }
        }
        n -= 8;
    }
    s->cnt = -n - 1;
    return (acc >> -n) & mask;
}
