/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64;

struct Callback_004AFDC8 {
    void (*fn)(void);
    int arg;
    Callback_004AFDC8(void (*f)(void), int a) : fn(f), arg(a) {}
};

struct Obj_004AFDC8 {
    char pad0[0x18];
    Callback_004AFDC8 m18;
    char pad20[8];
    u64 m28;
    Callback_004AFDC8 m30;
};

extern "C" void func_0047F060(Obj_004AFDC8 *o);
extern "C" void func_0047F3A8(void);

extern "C" void func_0047F6E8(Obj_004AFDC8 *o) {
    func_0047F060(o);
    o->m28 = 0;
    o->m30 = Callback_004AFDC8(0, 0);
    o->m18 = Callback_004AFDC8(func_0047F3A8, 0);
}
