struct Holder {
    int (*fn)(void);
    Holder(int (*f)(void)) : fn(f) {}
};
struct Holder2 {
    void (*fn)(void);
    Holder2(void (*f)(void)) : fn(f) {}
};

extern "C" int func_004A8AE0(void);
extern "C" void func_004A8AF8(void);
extern "C" char D_005981D8[];
extern "C" char D_005981E0[];
extern "C" void func_004A8AE8(void *self, const Holder &h, int n);
extern "C" void func_004A8B00(void *self, const Holder2 &h, int n);

/* Static initialisation of two callback globals; the inline constructors take a non-const self
   (a const one would load the callback's address before the object's). */
static inline void init1(void *self, int (*f)(void)) { func_004A8AE8(self, Holder(f), 0); }
static inline void init2(void *self, void (*f)(void)) { func_004A8B00(self, Holder2(f), 0); }

extern "C" void func_004A9570(int init, int prio) {
    if (prio == 0xFFFF && init == 1)
        init1(D_005981D8, func_004A8AE0);
    if (prio == 0xFFFF && init == 1)
        init2(D_005981E0, func_004A8AF8);
}
