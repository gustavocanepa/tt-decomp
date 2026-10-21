/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int size_t;
inline void *operator new(size_t, void *p) throw() { return p; }
struct Pair {
    float x, y;
    Pair(const Pair &p) { const float *q = &p.y; x = p.x; y = *q; }
};
extern "C" Pair *func_0053CE88(Pair *p, int n, const Pair *src, int unused0) {
    Pair *cur = p;
    for (; n != 0; --n, ++cur) new (cur) Pair(*src);
    return cur;
}
