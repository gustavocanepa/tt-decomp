/* The base class, named after its constructor (func_00480280); its vptr sits at 0xA4. */
struct func_00480280 {
    char pad[0xA4];
    func_00480280(int a, int b, int c);
    virtual ~func_00480280();
};

/* Named after its vtable (0x00689178) so that _vt$10D_00689178 resolves. */
struct D_005DA940 : func_00480280 {
    int mA8;
    int mAC;
    int mB0;
    int mB4;
    int mB8;
    int mBC;
    D_005DA940(int b4, int b, int a, int c, int bc);
    virtual ~D_005DA940();
};

D_005DA940::D_005DA940(int b4, int b, int a, int c, int bc) : func_00480280(a, b, c)
{
    mBC = bc;
    mB0 = a == 0;
    mB4 = b4;
    mB8 = 0;
}
