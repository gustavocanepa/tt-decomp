struct B0 { int a; B0(int v) { a = v; } virtual ~B0(); };
struct D_005DB720 : B0 {
    int c;
    D_005DB720(int x, int y);
    virtual ~D_005DB720();
};
D_005DB720::D_005DB720(int x, int y) : B0(x) {
    c = y;
}
