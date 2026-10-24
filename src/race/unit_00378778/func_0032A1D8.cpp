/* compiler: ee-gcc2.96-stl */
static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
typedef float f32; typedef int s32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
struct Bits { unsigned long a:32; unsigned long b:8; unsigned long c:8; unsigned long d:8; unsigned long e:8; };
static inline float root(float x) { float r; __asm__("sqrt.s %0, %1":"=f"(r):"f"(x)); return r; }
extern "C" float func_00317438(float) throw();
extern "C" void func_00318120(void *,float,float,float,float) throw();
extern "C" void func_00321898(void *) throw();
extern "C" void func_0032DCC0(void *,float);
extern "C" float func_002E6948(void *);
extern "C" float func_002E6960(void *);
extern "C" float func_002E6978(void *);
extern "C" float func_002E6988(void *);
extern "C" float func_005357F8(void *);
extern "C" void *func_004F6678(void *,int,unsigned int);
static inline void enable(char *p, int value) {
    unsigned long mask=0xFFFFFFFFFF00FFFFUL;
    unsigned long set=(unsigned long)value<<16;
    M2C_FIELD(p,int *,0xE8)=value;
    unsigned long bits = M2C_FIELD(p,unsigned long *,0x168);
    bits &= mask;
    bits |= set;
    M2C_FIELD(p,unsigned long *,0x168)=bits;
}
static inline void clear_vector(void *p) { func_004F6678(p,0,12); }
extern "C" void func_0032A1D8(char *arg0, s32 arg1, char *arg2, s32 arg3, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f22_3;
    f32 temp_f23;
    f32 temp_f23_2;
    f32 var_f0;
    f32 var_f15;
    f32 var_f21;
    f32 var_f23;
    f32 var_f24;
    unsigned long temp_a3;
    void *temp_s0;
    void *temp_s5;
    void *temp_a0;

    func_00321898(arg0);
    M2C_FIELD(arg0, int *, 0x148) = 0xC;
    temp_a3 = 0xFFFFFF00FFFFFFFFUL;
    M2C_FIELD(arg0, int *, 0x190) = arg1;
    M2C_FIELD(arg0, float *, 0x188) = (f32) (fparg0 * 0x1.e000000000000p+5f);
    M2C_FIELD(arg0, int *, 0x194) = -1;
    M2C_FIELD(arg0, int *, 0x184) = 0;
    M2C_FIELD(arg0, int *, 0x198) = 0;
    var_f24 = 0x1.3333320000000p-2f;
    unsigned long b = M2C_FIELD(arg0,unsigned long *,0x188);
    b &= 0xFFFFFF00FFFFFFFFUL;
    b &= 0xFFFF00FFFFFFFFFFUL;
    b |= 0x0000010000000000UL;
    M2C_FIELD(arg0,unsigned long *,0x188)=b;
    func_004F6678(arg0 + 0x1A0, 0, 0xC);
    func_004F6678(arg0 + 0x1AC, 0, 0xC);
    M2C_FIELD(arg0, int *, 0x1B8) = 0;
    func_004F6678(arg0 + 0x1BC, 0, 0xC);
    func_004F6678(arg0 + 0x1C8, 0, 0xC);
    M2C_FIELD(arg0, float *, 0x1D4) = 0x1.3333320000000p-2f;
    M2C_FIELD(arg0, float *, 0x1F0) = 0x1.6800000000000p+9f;
    M2C_FIELD(arg0, float *, 0x1F4) = 0x1.0000000000000p+0f;
    M2C_FIELD(arg0, float *, 0x200) = 0x1.e000000000000p+5f;
    M2C_FIELD(arg0, float *, 0x1EC) = 0x0.0p+0f;
    M2C_FIELD(arg0, float *, 0x1FC) = 0x0.0p+0f;
    M2C_FIELD(arg0, int *, 0x1F8) = 0;
    M2C_FIELD(arg0, float *, 0x204) = 0x0.0p+0f;
    M2C_FIELD(arg0, float *, 0x208) = 0x0.0p+0f;
    func_0032DCC0(arg0 + 0x20C, 0x1.666666p-2f);
    func_0032DCC0(arg0 + 0x21C, 0x1.666666p-2f);
    temp_a0 = M2C_FIELD(arg2, void * *, 0x10);
    if (temp_a0 != 0) {
        temp_s5 = M2C_FIELD(arg0, void * *, 0x180);
        temp_s0 = M2C_FIELD(temp_a0, void * *, 0x18);
        M2C_FIELD(arg0, float *, 0x19C) = func_005357F8(temp_s5);
        M2C_FIELD(arg0, float *, 0x1D4) = (f32) (func_005357F8(temp_s5) * 0x1.3333320000000p-2f);
        temp_f22 = func_005357F8(temp_s5) * 0x1.3333320000000p-2f;
        temp_f21 = (func_005357F8(temp_s5) * 0x1.3333320000000p-2f) + 0x1.6666660000000p-1f;
        temp_f23 = func_005357F8(temp_s5) * temp_f22;
        var_f15 = (func_005357F8(temp_s5) * 0x1.3333320000000p-2f) + 0x1.6666660000000p-1f;
        if (var_f15 < temp_f21) {
            var_f15 = temp_f21;
        }
        var_f21 = fparg0;
        func_00318120(arg0 + 0x1D8, temp_f22, temp_f21, temp_f23, var_f15);
        M2C_FIELD(arg0, float *, 0x1E8) = func_005357F8(temp_s5);
        M2C_FIELD(arg0, float *, 0x200) = (f32) ((func_005357F8(temp_s5) * 0x1.1800000000000p+5f) + 0x1.9000000000000p+4f);
        M2C_FIELD(arg0, float *, 0x204) = (f32) ((func_005357F8(temp_s5) * 0x1.4000000000000p+5f) - 0x1.4000000000000p+4f);
        M2C_FIELD(arg0, float *, 0x208) = (f32) ((func_005357F8(temp_s5) * 0x1.4000000000000p+5f) - 0x1.4000000000000p+4f);
        if (var_f21 > 0x1.4000000000000p+2f) {
            var_f21 = 0x1.4000000000000p+2f;
        }
        M2C_FIELD(arg0, float *, 0x1EC) = func_00317438(func_005357F8(temp_s5) * 0x1.6800000000000p+8f);
        if ((arg3 == 0) || (arg3 == 2)) {
            temp_f0 = func_005357F8(temp_s5) * 0x1.b800000000000p+7f;
            M2C_FIELD(arg0, int *, 0x198) = arg3;
            M2C_FIELD(arg0, float *, 0x1F0) = (temp_f0 * var_f21 * 0x1.3333320000000p-1f) + 0x1.9000000000000p+6f;
        } else {
            temp_f0_2 = func_005357F8(temp_s5) * 0x1.4000000000000p+7f;
            M2C_FIELD(arg0, int *, 0x198) = 1;
            M2C_FIELD(arg0, float *, 0x1F0) = temp_f0_2 + 0x1.4000000000000p+4f;
        }
        M2C_FIELD(arg0, float *, 0x1F4) = 0x1.0000000000000p+0f;
        if (func_005357F8(temp_s5) < 0x1.0000000000000p-1f) {
            M2C_FIELD(arg0, float *, 0x1F4) = -0x1.0000000000000p+0f;
        }
        M2C_FIELD(arg0, float *, 0x1FC) = (f32) (func_005357F8(temp_s5) * 0x1.6800000000000p+8f);
        temp_f21_2 = func_002E6948(temp_s0);
        temp_f20 = func_002E6960(temp_s0);
        temp_f22_2 = func_002E6978(temp_s0);
        temp_f23_2 = func_002E6988(temp_s0);
        var_f24 = root(temp_f21_2 * temp_f21_2 + temp_f22_2 * temp_f22_2);
        temp_f1 = root(temp_f20 * temp_f20 + temp_f22_2 * temp_f22_2);
        if (var_f24 < temp_f1) {
            var_f24 = temp_f1;
        }
        if (var_f24 < temp_f22_2) {
            var_f24 = temp_f22_2;
        }
        temp_f21_3 = temp_f22_2 * 0x1.0000000000000p-1f;
        float *v1=(float *)(arg0+0x1BC), *v2=(float *)(arg0+0x1C8);
        float *p1c0=(float *)(arg0+0x1C0), *p1c4=(float *)(arg0+0x1C4), *p1cc=(float *)(arg0+0x1CC), *p1d0=(float *)(arg0+0x1D0);
        *v1 = (f32) (((func_005357F8(temp_s5) * temp_f22_2) - temp_f21_3) * 0x1.6666660000000p-1f);
        *p1c0 = (f32) (func_005357F8(temp_s5) * temp_f23_2 * 0x1.9999980000000p-1f);
        *p1c4 = (f32) ((func_005357F8(temp_s5) * 0x1.8000000000000p+1f) - 0x1.8000000000000p+0f);
        *v2 = (f32) (((func_005357F8(temp_s5) * temp_f22_2) - temp_f21_3) * 0x1.6666660000000p-1f);
        *p1cc = (f32) (func_005357F8(temp_s5) * temp_f23_2 * 0x1.9999980000000p-1f);
        temp_f0_3 = (func_005357F8(temp_s5) * 0x1.8000000000000p+1f) - 0x1.8000000000000p+0f;
        *p1d0 = temp_f0_3;
        temp_f1_2 = absf(*p1d0);
        var_f23 = __builtin_fabsf(*p1c4);
        if (var_f23 < temp_f1_2) {
            var_f23 = temp_f1_2;
        }
        float *p1b0=(float *)(arg0+0x1B0), *p1b4=(float *)(arg0+0x1B4), *p1a4=(float *)(arg0+0x1A4), *p1a8=(float *)(arg0+0x1A8);
        temp_f22_3 = 1.0f - ((M2C_FIELD(arg0, float *, 0x200)-25.0f)/35.0f);
        temp_f22_3 = temp_f22_3 * 0x1.999998p-1f + 0x1.999998p-3f;
        *p1b0 = (f32) ((0x1.0000000000000p+1f * func_005357F8(temp_s5)) - 0x1.0000000000000p+0f);
        *p1b4 = (f32) ((temp_f22_3 * func_005357F8(temp_s5) * 0x1.0000000000000p+2f) + var_f23 + var_f24 + 0x1.9999980000000p-3f);
        *p1a4 = (f32) ((func_005357F8(temp_s5) * 0x1.8000000000000p+1f) - 0x1.8000000000000p+0f);
        *p1a8 = (f32) ((func_005357F8(temp_s5) * 0x1.0000000000000p+2f) + var_f23 + var_f24 + 0x1.9999980000000p-3f);
        long long mask = ~(0xFFLL << 16);
        long long set = 1LL << 16;
        M2C_FIELD(arg0, int *, 0xE8) = 1;
        M2C_FIELD(arg0, long long *, 0x168) = (M2C_FIELD(arg0, long long *, 0x168) & mask) | set;
    }
}
