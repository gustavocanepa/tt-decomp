/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct O1 { char b[0x20]; };
struct O2 { char b[0x10]; };
extern "C" void func_0042DCF8(O1 *);
extern "C" void func_0042E7B0(s32, O2 *);
extern "C" void SePlayer__Initialize(O1 *, O2 *, s32);
extern "C" void SePlayer__Play(O1 *, s32, s32, s32, float, float, float);
static inline s32 cl(s32 x, s32 limit) { return limit < x ? limit : x; }
static inline s32 volume(float p) {
    float f = p;
    if (f < 0.0f) f = -f;
    if (f >= 1.0f) return 0x7FFFFFFE;
    return cl((s32)(f * 2147483520.0f), 0x7FFFFFFE);
}
extern "C" void func_00347FA0(void *self, s32 arg1, float x, float y, float z, float w) {
    float p = x * y;
    if (p != 0.0f) {
        O1 o1;
        O2 o2;
        func_0042DCF8(&o1);
        func_0042E7B0(arg1, &o2);
        s32 a3 = volume(p);
        s32 s1 = cl(a3, 0x7FFFFFFE);
        SePlayer__Initialize(&o1, &o2, 1);
        SePlayer__Play(&o1, s1, 0, 0x40, z * p, w * p, 1.0f);
    }
}
