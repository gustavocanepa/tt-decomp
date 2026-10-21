/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" {
void func_001205B0(void *, int) throw();
void func_00120608(void *, void *) throw();
void func_00123E18(void *, s32 *, s32 *, s32 *);
void func_002931C8(void *, int);
void *func_002944D0(void *, void *, void *);
void func_00295180(void *);
void func_0029CEF0(void *, int);
void func_0029EA18(void *, s32);
void func_002A75A8(void *, s32);
void func_002C0FE8(void *);
void func_002C1050(void *);

void MCalendar__get_today(void **arg0, void *arg1) {
    s32 v[3];
    void *h[4];
    void *tmp[4];
    void *a[4];
    void *b[4];
    void *c[4];
    void **ph = h;
    func_00120608(ph, arg1);
    func_00123E18(ph[0], &v[0], &v[1], &v[2]);
    func_001205B0(ph, 2);
    func_00295180(ph);
    void *s2 = ph[0];
    void **pt = tmp;
    func_0029EA18(a, v[0]);
    func_002944D0(pt, s2, a);
    func_002A75A8(pt, 2);
    func_0029CEF0(a, 2);
    s2 = ph[0];
    func_0029EA18(b, v[1]);
    func_002944D0(pt, s2, b);
    func_002A75A8(pt, 2);
    func_0029CEF0(b, 2);
    s2 = ph[0];
    func_0029EA18(c, v[2]);
    func_002944D0(pt, s2, c);
    func_002A75A8(pt, 2);
    func_0029CEF0(c, 2);
    if (arg0 != ph) {
        void *p = ph[0];
        if (p != 0) func_002C0FE8(p);
        if (*arg0 != 0) func_002C1050(*arg0);
        *arg0 = p;
    }
    func_002931C8(ph, 2);
}
}
