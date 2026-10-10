typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct Dest {
    s32 w[8];
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" void *func_001324D8(void *arg0);
extern "C" void *func_00408B58(void *arg0);
extern "C" void *func_0040CFE0(void *arg0);
extern "C" int func_004107B0(void *arg0, Dest *dest);
extern "C" s32 func_00410900(Dest *arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, int arg1);
extern "C" void func_002C0FE8(void *p);
extern "C" void func_002C1050(void *p);

static inline void assign(void **dst, Handle *ph) {
    if ((void *)dst != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_002C0FE8(p);
        }
        if (*dst != 0) {
            func_002C1050(*dst);
        }
        *dst = p;
    }
}

extern "C" void func_0012D458(void **arg0, void *arg1) {
    Handle h0;
    Dest d;
    Handle h;
    func_00128470(&h0, arg1);
    if (func_004107B0(func_0040CFE0(func_00408B58(func_001324D8(h0.p))), &d) != 0) {
        s32 v = func_00410900(&d);
        Handle *ph = &h;
        func_0029EA18(ph, v != 0);
        assign(arg0, ph);
        func_0029CEF0(ph, 2);
    } else {
        Handle *ph = &h;
        func_0029EA18(ph, 0);
        assign(arg0, ph);
        func_0029CEF0(ph, 2);
    }
    func_00128418(&h0, 2);
}
