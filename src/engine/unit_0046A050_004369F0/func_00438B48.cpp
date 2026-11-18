/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { int pad; int x, y; int pad2[3]; int s; int pad3[2]; int a; };
struct Header { int mark, value; int *table[8]; };
extern "C" int func_00438B48(int ***out, Header *h) {
    if (h->mark >= 0) {
        h->mark = -h->mark;
        for (int i = 0; i < 8; i++) {
            int n = (int)h->table[i];
            if (n == 0) continue;
            int *blk = (int *)((int)h + n);
            h->table[i] = blk;
            n = blk[0];
            if (n == 0) {
                h->table[i] = 0;
                continue;
            }
            Rec *r = (Rec *)(blk + 1);
            for (int j = 0; j < n; j++, r++) {
                *(float *)&r->s = (float)r->s * 0x1p-12f;
                *(float *)&r->x = -(float)r->x * 0x1p-12f;
                *(float *)&r->y = -(float)r->y * 0x1p-12f;
                *(float *)&r->a = (float)r->a * 0x1.921fb4p2f * 0x1p-12f + 0x1.921fb4p1f;
            }
        }
    }
    *out = h->table;
    return h->value;
}
