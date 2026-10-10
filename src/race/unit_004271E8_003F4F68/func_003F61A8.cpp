typedef long long s64;
struct func_00400D68 {
    func_00400D68();
    virtual ~func_00400D68();
};
struct D_005D8A38 : func_00400D68 {
    int m4;
    s64 a[1024];
    s64 b[128];
    int m2408;
    D_005D8A38();
    virtual ~D_005D8A38();
};

D_005D8A38::D_005D8A38() {
    m2408 = 0;
    for (int i = 0; i < 1024; i++) a[i] = -1;
    for (int i = 0; i < 128; i++) b[i] = -1;
}
