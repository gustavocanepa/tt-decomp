/* compiler: ee-gcc2.9-991111 */
struct Eight { char b[8]; };
struct Blk { struct Blk *next; unsigned used:1; unsigned key:31; unsigned flag:1; unsigned size:31; };
extern struct { char pad[0xC]; char *head; int p10; } D_0077A008;

int func_004D3B50(unsigned arg) {
    struct Blk *prev, *p, *nx, *t0, *a1;
    int cnt;
    if (arg & 0xFF) goto error;
    {
        unsigned key = arg >> 8;
        prev = 0;
        p = (struct Blk *)(D_0077A008.head + 0x1C);
        for (;;) {
            if (p == 0) break;
            if (p->size != 0 && p->key == key) break;
            prev = p;
            p = p->next;
        }
    }
    if (p == 0 || !p->used) {
error:
        return -1;
    }
        {
            nx = p->next;
            cnt = 0;
            p->used = 0;
            t0 = 0;
            if (nx != 0 && !nx->used && nx->size != 0) {
                D_0077A008.p10 = D_0077A008.p10 - 1;
                p->size += nx->size;
                t0 = nx;
                cnt = 1;
            }
            if (prev != 0 && !prev->used) {
                D_0077A008.p10 = D_0077A008.p10 - 1;
                prev->size += p->size;
                t0 = p;
                cnt = cnt + 1;
            }
            if (cnt == 0) return 0;
            p = t0;
            while (cnt-- != 0) p = p->next;
            if (p != 0) {
                do {
                    prev = t0->next;
                    *t0 = *p;
                    t0->next = prev;
                    t0 = prev;
                    p = p->next;
                } while (p != 0);
            }
            return 0;
        }
    return -1;
}
