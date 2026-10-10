/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
    float x, y, z, w;
    V() {}
    V(const V &o) { *(u128 *)this = *(const u128 *)&o; }
} __attribute__((aligned(16)));
extern "C" void func_0044DB80(int a, V *out);
extern "C" V func_003E62C8(int a) {
    V r;
    func_0044DB80(a, &r);
    return r;
}
