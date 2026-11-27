/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int I128 __attribute__((mode(TI)));
struct Obj;
struct S;
struct Vec3 { float x, y, z; };
extern "C" I128 func_0034AE70(Obj *self, int idx);
extern "C" float func_0034ADD8(S *arg0, int arg1);
extern "C" float func_00317438(float a);
/* Lane extraction from a 128-bit GPR holding x, y, z, w. */
static inline float lane0(I128 q) { float f; __asm__("mtc1 %1, %0" : "=f"(f) : "r"(q)); return f; }
static inline I128 upperHalf(I128 q) { I128 r; __asm__("pcpyud %0, %1, %1" : "=r"(r) : "r"(q)); return r; }
static inline I128 shiftDown32(I128 q) { I128 r; __asm__("dsra32 %0, %1, 0" : "=r"(r) : "r"(q)); return r; }
extern "C" void func_003A7E48(Vec3 *out, float *angle, Obj *obj, int idx) {
    I128 q = func_0034AE70(obj, idx);
    out->x = lane0(q);
    out->z = lane0(upperHalf(q));
    out->y = lane0(shiftDown32(q));
    float deg = func_0034ADD8((S *)obj, idx) * 57.29578f;
    *angle = deg;
    *angle = func_00317438(360.0f - deg);
}
