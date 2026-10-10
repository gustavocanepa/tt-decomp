typedef int s32;

/* The base class, named after its constructor so that __13func_0043C310 resolves. */
struct func_00404F20 {
    char pad0[8];
    s32 m8;
    func_00404F20(const char *name, const char *type, s32 n);
    virtual ~func_00404F20();
    void func_00404310(s32 n);
};

extern char D_00585888[];

/* No known name: named after its vtable (0x006880C0) so that _vt$10D_006880C0 resolves. */
struct D_005D9640 : func_00404F20 {
    char pad10[0x14];
    char m24;
    D_005D9640();
    virtual ~D_005D9640();
};

D_005D9640::D_005D9640() : func_00404F20(0, D_00585888, m8) {
    func_00404310(0);
    m24 = 1;
}
