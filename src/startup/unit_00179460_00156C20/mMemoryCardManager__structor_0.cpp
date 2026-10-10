typedef int s32;

/* The base class; its constructor is func_002A7618. Its vptr sits at 0x4. */
struct func_002A7618 {
    s32 m0;
    func_002A7618();
    virtual ~func_002A7618();
};

/* A member object; its constructor is func_001DCE88. */
struct func_001DCE88 {
    s32 w[2];
    func_001DCE88();
};

struct Pair {
    s32 a;
    s32 b;
    Pair() : a(0), b(0) {}
};

/* Named after its vtable so the compiler-made vptr store _vt$10D_0065CE20 resolves. */
struct D_005A7A58 : func_002A7618 {
    char pad8[8];
    func_001DCE88 m10;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    s32 m28;
    Pair m2C;
    D_005A7A58();
    virtual ~D_005A7A58();
};

D_005A7A58::D_005A7A58() : m18(0), m1C(0), m20(0), m24(0) {
    m28 = 0;
}
