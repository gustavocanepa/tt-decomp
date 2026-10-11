class B {
    int a;
    int b;
public:
    virtual ~B() __asm__("func_004ACAB8");
};

class D_005A49C0 : public B {
public:
    virtual ~D_005A49C0() {}
};

extern D_005A49C0 D_00578E28;
extern D_005A49C0 D_00578E68;

extern "C" void func_00100708(D_005A49C0 *o);
extern "C" void func_00100768(D_005A49C0 *o);

extern "C" void func_00100D50(int init, int prio)
{
    if (prio == 0xFFFF && init == 1) {
        func_00100708(&D_00578E28);
    }
    if (prio == 0xFFFF && init == 1) {
        func_00100768(&D_00578E68);
    }
    if (prio == 0xFFFF && init == 0) {
        D_00578E68.D_005A49C0::~D_005A49C0();
    }
    if (prio == 0xFFFF && init == 0) {
        D_00578E28.D_005A49C0::~D_005A49C0();
    }
}
