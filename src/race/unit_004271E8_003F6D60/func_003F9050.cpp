struct Rec { int x[11]; };
struct Tab { Rec r[10]; };

extern "C" void func_003F9050(Tab *t, Rec *src, int pos) {
    int k = 9;
    if (pos < k) {
        do {
            t->r[k] = t->r[k - 1];
            k--;
        } while (pos < k);
    }
    t->r[pos] = *src;
}
