/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct H0;
struct H1;
struct H2;
struct H3;
struct H4;

extern "C" void func_001DF1F8(H1 *, s32);
extern "C" void func_001DF250(H1 *, void *);
extern "C" void func_001ED038(H0 *, s32) throw();
extern "C" void func_001ED090(H0 *, s32) throw();
extern "C" void func_001ED6D0(void *, void *);
extern "C" void func_001ED768(void *, H4 *);
extern "C" void func_00202788(H2 *, s32);
extern "C" void func_002027E0(H2 *, void *);
extern "C" void func_0022F7C0(void *, void *);
extern "C" void func_0022F820(void *, void *);
extern "C" void func_002931C8(H4 *, s32);
extern "C" void func_00293220(H4 *, void *);
extern "C" void func_002ADBF0(H3 *, s32);
extern "C" void func_002ADC48(H3 *, void *);
extern "C" void *func_002AFE68(void *);

struct H0 {
    void *p; char pad[12];
    H0(s32 a) { func_001ED090(this, a); }
    ~H0() { func_001ED038(this, 2); }
};
struct H1 {
    void *p; char pad[12];
    H1(void *s) { func_001DF250(this, s); }
    ~H1() { func_001DF1F8(this, 2); }
};
struct H2 {
    void *p; char pad[12];
    H2(void *s) { func_002027E0(this, s); }
    ~H2() { func_00202788(this, 2); }
};
struct H3 {
    void *p; char pad[12];
    H3(void *s) { func_002ADC48(this, s); }
    ~H3() { func_002ADBF0(this, 2); }
};
struct H4 {
    void *p; char pad[12];
    H4(void *s) { func_00293220(this, s); }
    ~H4() { func_002931C8(this, 2); }
};

static inline void *ptr(void *h) { return *(void **)h; }

extern "C" void MScriptEvent__global_0082EB40(void *a0, s32 a1, s32 level, char *src) {
    if (level >= 3) {
        H0 h0(a1);
        H1 h1(src);
        func_0022F7C0(h0.p, ptr(&h1));
        H2 h2(src + 4);
        func_0022F820(h0.p, ptr(&h2));
        H3 h3(src + 8);
        {
            void *tp = h0.p;
            func_001ED6D0(tp, func_002AFE68(ptr(&h3)));
        }
        if (level >= 4) {
            H4 h4(src + 0xC);
            func_001ED768(h0.p, &h4);
        }
    }
}
