typedef int s32;

typedef void (*Fn)(void);
extern Fn D_0059D534;
extern "C" void func_004C4F18(s32, s32);
extern "C" void func_004CF3C0(s32, void (*)(void), s32);
extern "C" void func_004C4E70(void);
extern "C" void func_004C4E90(void);

extern "C" void func_004C4EB0(void) {
    func_004C4F18(0x3FFF, 0);
    Fn f = func_004C4E70;
    D_0059D534 = f;
    func_004CF3C0(0, func_004C4E90, 0);
}
