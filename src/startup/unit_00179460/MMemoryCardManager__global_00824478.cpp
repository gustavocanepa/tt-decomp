/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Hdr;

extern char D_005E2AC8[];
extern char D_005E3048[];
extern "C" void func_001564E0(void *, int);
extern "C" void func_00156538(void *);
extern "C" s32 func_00156700(void *, const char *);
extern "C" void func_00158D38(void *, s32, s32);
extern "C" void func_0029CEF0(void *, int);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(void *);
extern "C" s32 func_0029EA18(void *, int);
extern "C" void func_002ADBF0(void *, int);
extern "C" void func_002ADC48(void *, void *);
extern "C" char **func_002AFE68(void *);
extern "C" void func_002C0FE8(void *);
extern "C" void func_002C1050(void *);

extern "C" void MMemoryCardManager__global_00824478(int unused, void *arg1, int count, void *obj) {
    Hdr *a[4];
    void *h[4];
    void *r[4];
    void *t[4];
    func_00156538(a);
    if (count > 0) {
        void **ph = h;
        func_002ADC48(ph, obj);
        void **pr = r;
        func_0029EA18(pr, 0);
        if (count >= 2) {
            void **pt = t;
            func_0029CF48(pt, (char *)obj + 4);
            if (pr != pt) {
                void *nv = pt[0];
                if (nv != 0)
                    func_002C0FE8(nv);
                if (pr[0] != 0)
                    func_002C1050(pr[0]);
                pr[0] = nv;
            }
            func_0029CEF0(pt, 2);
        }
        Hdr *a0 = a[0];
        char **sp = func_002AFE68(ph[0]);
        const char *s;
        if (((s32 *)*sp)[-4] == 0) {
            s = D_005E2AC8;
        } else {
            (*sp)[((s32 *)*sp)[-4]] = 0;
            s = *sp;
        }
        s32 w = func_00156700(D_005E3048, s);
        func_00158D38(a0, w, func_0029E9F0(pr[0]));
        func_0029CEF0(pr, 2);
        func_002ADBF0(ph, 2);
    }
    func_001564E0(a, 2);
}
