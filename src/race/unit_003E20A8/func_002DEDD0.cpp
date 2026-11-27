/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

/* Three floats func_005AE2E8 as one 64-bit and one 32-bit word (no 16-byte alignment). */
struct Point {
    u64 xy;
    u32 z;
} __attribute__((packed));

struct Body {
    char pad[0x10];
    Point pos;
};

extern "C" void func_002E0488(Body *body, u128 *m) throw();

/* Loads the body's rotation into VU0 vf20-vf22 and its position into vf23. */
extern "C" void func_002DEDD0(Body *body) {
    u128 m[4];
    u128 v;
    u64 xy;
    u32 z;

    func_002E0488(body, m);
    __asm__ volatile("vnop");
    __asm__ volatile("lqc2 $vf20, %0" : : "m"(m[0]));
    __asm__ volatile("lqc2 $vf21, %0" : : "m"(m[1]));
    __asm__ volatile("lqc2 $vf22, %0" : : "m"(m[2]));
    __asm__ volatile("lqc2 $vf23, %0" : : "m"(m[3]));
    z = body->pos.z;
    xy = body->pos.xy;
    __asm__("pcpyld %0, %1, %2" : "=r"(v) : "0"(z), "r"(xy));
    __asm__ volatile("qmtc2.ni %0, $vf23" : : "r"(v));
}
