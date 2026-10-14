/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
extern "C" void func_0027FB18(void *, int) throw();
extern "C" void func_0027FB70(void *) throw();
extern "C" void func_00280748(void *, u8 *, void *);
extern "C" void func_00202788(void *, int);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_002ADBF0(void *, int);
extern "C" void func_002ADC48(void *, void *);
extern "C" u8 *func_002AFE68(void *);

extern "C" void MShell__execute(void *arg0, void *arg1, int arg2, char *arg3) {
    void *sp[4];
    void *sp10[4];
    void *sp20[4];
    if (arg2 > 0) {
        func_0027FB70(sp);
        void **p = sp10;
        func_002ADC48(p, arg3);
        void **q;
        if (arg2 >= 2) {
            q = sp20;
            func_002027E0(q, arg3 + 4);
            void *h = sp[0];
            func_00280748(h, func_002AFE68(p[0]), q[0]);
            func_00202788(q, 2);
        } else {
            void *h = sp[0];
            func_00280748(h, func_002AFE68(p[0]), 0);
        }
        func_002ADBF0(p, 2);
        func_0027FB18(sp, 2);
    }
}
