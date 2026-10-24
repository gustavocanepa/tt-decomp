/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { float a, b, key, d; };
extern "C" void func_002E2170(void *self, E *arr, int lo, int hi) {
    if (hi >= 0) {
        int i = lo;
        int j = hi;
        E *pj = (E *)((hi << 4) + (int)arr);
        E *pi = (E *)((lo << 4) + (int)arr);
        float pivot = arr[(lo + hi) >> 1].key;
        for (;;) {
            while (pi->key < pivot) {
                pi++;
                i++;
            }
            while (pivot < pj->key) {
                pj--;
                j--;
            }
            if (i < j) {
                E t = *pi;
                i++;
                j--;
                *pi++ = *pj;
                *pj-- = t;
            } else {
                break;
            }
        }
        if (lo < i - 1) func_002E2170(self, arr, lo, i - 1);
        if (j + 1 < hi) func_002E2170(self, arr, j + 1, hi);
    }
}
