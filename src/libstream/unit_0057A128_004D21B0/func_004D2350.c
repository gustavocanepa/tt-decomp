/* compiler: ee-gcc2.9-991111 */
struct Export { int a, b, c, d; };
struct Lists { struct Export *a, *b; };
extern int D_005A0BB0, D_00779FF4;
extern unsigned int D_00779FF0;
extern struct Export D_005DC0F4;
extern char D_005DC160[], D_005DC264[];
extern char D_00613950[], D_00613978[], D_00613990[], D_006139A0[];
extern void func_004D27D8(void);
extern int func_004D2978(void);
extern int func_004D29D0(void *, unsigned int);
extern void *func_004D2FB8(int *);
extern struct Lists *func_004D3E80(int *);
extern int func_004D3EA0(int);
extern int func_004D4748(void *);
extern int func_004D59E0(int);
extern int *func_004D5BB0(int *);
extern void func_004D9D90(unsigned int *, unsigned int *);
extern int func_004D9F60(const char *, int, int, int, int, int *);
extern void *func_004F6678(void *, int, unsigned int);
extern int func_004FAC70(void);
extern void func_004FD2D0(const char *, ...);
extern int func_005058A8(int (*)(void *));
int func_004D2350(int priority, void *start, unsigned int size, int max) {
    int n, status, result;
    void *p;
    struct Lists *list;
    int *state;
    if (D_005A0BB0 == 0) {
        p = func_004D2FB8(&n);
        func_004F6678(p, 0, n);
        list = func_004D3E80(&n);
        func_004F6678(list, 0, n);
        list->b = &D_005DC0F4;
        list->a = &D_005DC0F4;
        D_005DC0F4.c = 0;
        D_005DC0F4.d = 0;
        state = func_004D5BB0(&n);
        func_004F6678(state, 0, n);
        state[2] = -1;
        state[3] = -1;
        state[0] = -1;
        if (!func_004D29D0(start, size)) return 0x8105000C;
        result = func_004D3EA0(max);
        if (result < 0) return result;
        result = func_004D59E0(priority);
        if (result < 0) return result;
        D_005A0BB0 = 1;
        func_004D2978();
        func_004D4748(D_005DC160);
        func_004D4748(D_005DC264);
        result = func_005058A8(func_004D4748);
        if (result < 0) {
            func_004FD2D0(D_00613950, result);
            for (;;) {}
        }
        if (func_004FAC70() & 0x100) goto fallback;
        {
            result = func_004D9F60(D_00613978, 0, 0, 0, 0, &status);
            if (result < 0) {
                result = func_004D9F60(D_00613990, 0, 0, 0, 0, &status);
                if (result < 0) {
                    func_004FD2D0(D_006139A0, result);
                    goto fallback;
                }
            }
            if (result == 0 && status == 1) {
fallback:
                func_004D27D8();
                D_00779FF4 = -1;
            } else {
                D_00779FF4 = result;
            }
        }
        func_004D9D90(&D_00779FF0, 0);
    }
    return 0;
}
