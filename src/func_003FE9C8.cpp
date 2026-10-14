/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { char p[8]; unsigned char used; unsigned char act; signed char id; char q[5]; };
struct P { unsigned int count; unsigned short cur; char p6; unsigned char flag; char q[8]; E e[1]; };
extern "C" void func_003FE6A8(void *) throw();

extern "C" E *func_003FE9C8(P *p) {
    unsigned int i = 0;
    int cnt = 0;
    E *found = 0;
    unsigned int n = p->count;
    if (n != 0) {
        unsigned char *q = (unsigned char *)p + 0x19;
        do {
            unsigned char a = *q;
            q += 16;
            i++;
            if (a) cnt++;
        } while (i < n);
    }
    if (cnt != 0) p->cur = p->cur % cnt;
    else p->flag = 1;
    int s0 = p->cur;
    for (;;) {
        if (p->flag != 0) return 0;
        unsigned int m = p->count;
        i = 0;
        if (m != 0) {
            do {
                E *e = &p->e[i];
                if (s0 == e->id) {
                    if (e->used == 0) {
                        e->used = 1;
                        found = e;
                    } else {
                        i = 0;
                        s0++;
                        continue;
                    }
                    s0++;
                    s0 %= cnt;
                    if (s0 == 0) func_003FE6A8(p);
                    break;
                }
            } while (++i < m);
        }
        if (found != 0) {
            p->cur = s0;
            return found;
        }
    }
}
