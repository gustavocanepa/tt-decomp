/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s128 __attribute__((mode(TI)));
inline void *operator new(unsigned int, void *p) { return p; }
struct Pair {
    s128 m0, m10;
    Pair() {}
    Pair(const Pair &o) : m0(o.m0), m10(o.m10) {}
};
struct D_005D7288 : Pair { virtual ~D_005D7288(); };
extern "C" void func_0055F940(D_005D7288 *dst, const D_005D7288 *src) {
    new (dst) D_005D7288(*src);
}
