/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

/* Three floats func_005AE2E8 and written as one 64-bit and one 32-bit word (no 16-byte alignment). */
struct Point {
    u64 xy;
    u32 z;
} __attribute__((packed));

/* out = the VU0 rotation vf20-vf22 applied to in. */
extern "C" void func_002DDD18(Point *out, Point *in) {
    u128 v;
    u64 xy;
    u32 z;
    u64 lo;
    u32 hi;

    __asm__ volatile("vnop");
    z = in->z;
    xy = in->xy;
    __asm__("pcpyld %0, %1, %2" : "=r"(v) : "0"(z), "r"(xy));
    __asm__ volatile("qmtc2.ni %0, $vf1" : : "r"(v));
    __asm__ volatile("vmulax.xyzw ACC, $vf20, $vf1x");
    __asm__ volatile("vmadday.xyzw ACC, $vf21, $vf1y");
    __asm__ volatile("vmaddz.xyzw $vf1, $vf22, $vf1z");
    __asm__ volatile("qmfc2.ni %0, $vf1" : "=r"(lo));
    __asm__("pcpyud %0, %1, %1" : "=r"(hi) : "r"(lo));
    out->xy = lo;
    out->z = hi;
}
