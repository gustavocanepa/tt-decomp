typedef int s32;

typedef void (*Fn)(void);
extern Fn D_0059D528;
extern "C" void func_004C40D8(s32, s32);
extern "C" void func_004CF3C0(s32, void (*)(void), s32);
extern "C" void func_004C3FB8(void);
extern "C" void func_004C3FD8(void);

extern "C" void func_004C4070(void) {
    func_004C40D8(0x3FFF, 0);
    Fn f = func_004C3FB8;
    D_0059D528 = f;
    func_004CF3C0(2, func_004C3FD8, 0);
}
