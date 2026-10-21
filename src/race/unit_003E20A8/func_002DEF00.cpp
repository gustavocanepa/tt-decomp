/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef unsigned int u32;
typedef unsigned long u64;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

/* Three floats func_005AE2E8 and written as one 64-bit and one 32-bit word (no 16-byte alignment). */
struct Point {
    u64 xy;
    u32 z;
} __attribute__((packed));

struct Vec3 {
    f32 x, y, z;
};

struct Body;

extern "C" void func_002DEDD0(Body *body) throw();
extern "C" void func_002DDD18(Point *out, Point *in) throw();
extern "C" void func_002DDC80(Vec3 *out, Vec3 *a, Vec3 *b) throw();

/* out = a x (local rotated back into the body's frame: the transposed VU0 rotation). */
extern "C" void func_002DEF00(Body *body, Vec3 *out, Vec3 *a, Point *local) {
    Point v;
    u128 r0, r1, r2, r3;
    u128 t0, t1, t2, t3;

    func_002DEDD0(body);
    __asm__ volatile("qmfc2.ni %0, $vf20" : "=r"(r0));
    __asm__ volatile("qmfc2.ni %0, $vf21" : "=r"(r1));
    __asm__ volatile("qmfc2.ni %0, $vf22" : "=r"(r2));
    __asm__ volatile("qmfc2.ni %0, $vf23" : "=r"(r3));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t0) : "r"(r1), "r"(r0));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t1) : "r"(r1), "r"(r0));
    __asm__ volatile("pextlw %0, %1, %2" : "=r"(t2) : "r"(r3), "r"(r2));
    __asm__ volatile("pextuw %0, %1, %2" : "=r"(t3) : "r"(r3), "r"(r2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r0) : "r"(t2), "r"(t0));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r1) : "r"(t0), "r"(t2));
    __asm__ volatile("pcpyld %0, %1, %2" : "=r"(r2) : "r"(t3), "r"(t1));
    __asm__ volatile("pcpyud %0, %1, %2" : "=r"(r3) : "r"(t1), "r"(t3));
    __asm__ volatile("qmtc2.ni %0, $vf20" : : "r"(r0));
    __asm__ volatile("qmtc2.ni %0, $vf21" : : "r"(r1));
    __asm__ volatile("qmtc2.ni %0, $vf22" : : "r"(r2));
    __asm__ volatile("qmtc2.ni %0, $vf23" : : "r"(r3));
    func_002DDD18(&v, local);
    func_002DDC80(out, a, (Vec3 *)&v);
}
