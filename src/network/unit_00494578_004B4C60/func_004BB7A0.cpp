/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern u32 D_00776B90;
extern "C" int func_005038D8(void);
extern "C" int func_00503928(void);
extern "C" int func_004FB368(void *);
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")
extern "C" void func_004BB7A0(void) {
    u32 *busy = &D_00776B90;
    func_005038D8();
    *busy = 5;
    func_00503928();
    func_004FB368((void *)8);
    u32 status = REG(0x1000E010);
    if (status & 8) {
        REG(0x1000E010) = 8;
        (void)REG(0x1000E010); SYNC();
    }
    if (!(status & 0x80000)) {
        REG(0x1000E010) = 0x80000;
        (void)REG(0x1000E010); SYNC();
    }
    REG(0x1000F590) = 0;
    (void)REG(0x1000F590); SYNC();
}
