/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Mat { float m[16]; };
struct St { char pad[8]; int cur; Mat mats[1]; };
static inline int less(int i, int n) { return i < n; }
extern "C" void func_003F4400(St *st, float *out) {
    int i = 0;
    int current = st->cur;
    do {
        Mat *m = &st->mats[current];
        out[i] = m->m[i];
        i++;
        current = st->cur;
    } while (less(i, 16));
}
