/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s128 __attribute__((mode(TI)));
typedef float f32;

inline void *operator new(unsigned int, void *p) { return p; }

/* The implicit copy constructor of a three-level class, inlined: the POD base's members are
   copied before the first vptr store, which is the reason for the POD base. The root class's
   own vptr store is dead (overwritten before any read) and disappears, so the two stores left
   are those of the middle class (vtable 0x00686570) and of the class itself (0x00686518); the
   classes with no known names are named after their vtables so that _vt$10D_... resolves. */
struct Pair_005FFC10 {
    s128 m0;
    s128 m10;
    Pair_005FFC10() {}
    Pair_005FFC10(const Pair_005FFC10 &o) : m0(o.m0), m10(o.m10) {}
};

struct Root_005FFC10 : Pair_005FFC10 {
    virtual ~Root_005FFC10();
};

struct D_005D7238 : Root_005FFC10 {
    s128 m30;
    f32 m40;
    f32 m44;
};

struct D_005D71E8 : D_005D7238 {
    s128 m50;
    s128 m60;
    virtual ~D_005D71E8();
};

extern "C" void func_0055FB20(D_005D71E8 *dst, const D_005D71E8 *src) {
    new (dst) D_005D71E8(*src);
}
