class A {
    int data[0xC];
public:
    ~A() __asm__("func_004AE9F0");
};

class B {
    int a;
    int b;
public:
    virtual ~B() __asm__("func_004AC770");
};

class D_005DA5E0 : public B {
public:
    virtual ~D_005DA5E0() {}
};

extern A D_0058C558;
extern D_005DA5E0 D_0058C588;

extern "C" void func_004AE9C0(A *o);
extern "C" void func_0056E480(D_005DA5E0 *o);

extern "C" void func_0047D6D8(int init, int prio)
{
    if (prio == 0xFFFF && init == 1) {
        func_004AE9C0(&D_0058C558);
    }
    if (prio == 0xFFFF && init == 1) {
        func_0056E480(&D_0058C588);
    }
    if (prio == 0xFFFF && init == 0) {
        D_0058C588.D_005DA5E0::~D_005DA5E0();
    }
    if (prio == 0xFFFF && init == 0) {
        D_0058C558.~A();
    }
}
