struct D_00689DD8 {
    int f0;
    D_00689DD8(int a) __asm__("func_004A9270");
    virtual ~D_00689DD8();
};

struct D_005DADB0 : D_00689DD8 {
    int f8;
    D_005DADB0(int x, int y) __asm__("func_004A9768");
    virtual ~D_005DADB0();
};

D_005DADB0::D_005DADB0(int x, int y) : D_00689DD8(y) {
    f8 = x;
}
