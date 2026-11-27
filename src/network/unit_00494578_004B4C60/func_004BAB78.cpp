/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
extern "C" int func_005038D8(void);
extern "C" int func_00503928(void);
extern u32 D_00776B80;
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")
extern "C" int func_004BAB78(u32 addr, u32 size) {
    func_005038D8();
    u32 old = REG(0x1000F520);
    volatile u32 *enable = (volatile u32 *)0x1000F590;
    volatile u32 *channel = (volatile u32 *)0x1000B000;
    *enable = old | 0x10000;
    (void)*enable; SYNC();
    *channel &= ~0x100;
    (void)*channel; SYNC();
    *enable = old;
    (void)*enable; SYNC();
    func_00503928();
    REG(0x1000B010) = addr & 0x0FFFFFFF;
    SYNC();
    u32 n = size >> 4;
    u32 count = n <= 0xFFF0u ? n : 0xFFF0u;
    D_00776B80 = ((size + 15) >> 4) - count;
    REG(0x1000B020) = count;
    SYNC();
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
    func_005038D8();
    u32 old2 = REG(0x1000F520);
    REG(0x1000F590) = old2 | 0x10000;
    (void)REG(0x1000F590); SYNC();
    REG(0x1000B000) |= 0x100;
    (void)REG(0x1000B000); SYNC();
    REG(0x1000F590) = old2 & ~0x10000;
    (void)REG(0x1000F590); SYNC();
    return func_00503928();
}
