/* Named after their constructors so that the calls resolve. */
struct func_004AE9C0 {
    char data[0x30];
    func_004AE9C0();
};

struct D_005A4D50;

struct func_00108818 {
    char data[0x14];
    func_00108818(D_005A4D50 *owner, int arg, int flags);
};

/* The root class of func_00108F78.cpp; named after its vtable (0x00659F18). */
struct D_005A4D50 {
    func_004AE9C0 m0;
    func_00108818 m30;
    func_00108818 m44;
    int m58;
    int m5C;
    int m60;
    virtual ~D_005A4D50();
    D_005A4D50(int a, int b);
};

D_005A4D50::D_005A4D50(int a, int b) : m30(this, a, 0), m44(this, b, 0) {
    m58 = 0;
    m5C = 0;
    m60 = 0;
}
