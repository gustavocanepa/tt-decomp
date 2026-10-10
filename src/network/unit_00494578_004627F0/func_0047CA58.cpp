struct D_005DA4F8;
struct func_0056DF70 {
    func_0056DF70(D_005DA4F8 *owner);
    int d[3];
};
struct func_004AE9C0 {
    func_004AE9C0();
    int d[12];
};
struct func_0056DF88 {
    func_0056DF88();
    int d[3];
};
struct Pair {
    int a, b;
    Pair() : a(0), b(0) {}
};

struct D_005DA4F8 {
    func_0056DF70 link;
    int m0C;
    func_004AE9C0 m10;
    func_0056DF88 m40;
    func_0056DF88 m4C;
    func_0056DF88 m58;
    func_004AE9C0 m64;
    int m94;
    Pair m98;
    int mA0;
    D_005DA4F8();
    virtual ~D_005DA4F8();
};

D_005DA4F8::D_005DA4F8() : link(this), m0C(0), m94(0), mA0(0) {}
