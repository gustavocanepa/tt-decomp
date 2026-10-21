/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Row { unsigned long long key; char rest[0x230]; };
struct Tab { int pad; Row *rows; int count; };
extern "C" unsigned long long func_0040FC00(int);
extern "C" void func_003F9A88(Row *) throw();
extern "C" Row *func_003FA6A0(Tab *t, int a) {
    unsigned long long k = func_0040FC00(a);
    int n = t->count;
    for (int i = 0; i < n; ++i) {
        Row *r = t->rows + i;
        if (r->key == k) return r;
        if (r->key == (unsigned long long)-1 || k < r->key) {
            if (r->key != (unsigned long long)-1) {
                for (int j = n - 1; i < j; --j) {
                    Row *d = t->rows + j;
                    Row *s = d - 1;
                    if (s->key != (unsigned long long)-1) *d = *s;
                }
            }
            func_003F9A88(r);
            r->key = k;
            return r;
        }
    }
    return 0;
}
