/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned long u64;

extern "C" void func_0047F3A8(void *arg);

struct Callback {
    void (*fn)(void *);
    s32 arg;
    Callback() : fn(0), arg(0) {}
    Callback(void (*f)(void *)) : fn(f), arg(0) {}
    Callback(const Callback &o) : fn(o.fn), arg(o.arg) {}
};

struct func_0047EFF0 {
    s32 m0, m4, m8, mC, m10, m14;
    Callback cb;
    func_0047EFF0();
    virtual ~func_0047EFF0();
};

struct D_005DA768 : func_0047EFF0 {
    u64 m28;
    Callback cb30;
    s32 m38;
    D_005DA768(const Callback &c, s32 v);
    virtual ~D_005DA768();
};

D_005DA768::D_005DA768(const Callback &c, s32 v) : m28(0), cb30(c), m38(0) {
    cb = Callback(func_0047F3A8);
    m10 = v;
}
