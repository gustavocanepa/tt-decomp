/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;

#define VIF1_STAT (*(volatile u32 *)0x10003C00)
#define VIF1_FBRST (*(volatile u32 *)0x10003C10)
#define GIF_CTRL (*(volatile u32 *)0x10003000)
#define GIF_MODE (*(volatile u32 *)0x10003010)
#define GIF_STAT (*(volatile u32 *)0x10003020)

extern "C" s32 func_0046EA28(s32 ch);

/* Waits for VIF1, VU1 and the GIF to go idle, resetting each one that stays busy too long. */
extern "C" void func_0046FB98(void) {
    s32 timeout = 0x1000000;
    u32 stat;

    func_0046EA28(1);
    func_0046EA28(2);
    while (VIF1_STAT & 0x1F000003) {
        if (--timeout < 0)
            VIF1_FBRST = 1;
    }
    __asm__ volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    while (stat & 0x100) {
        if (--timeout < 0) {
            u32 fbrst;
            __asm__ volatile("cfc2.ni %0, $vi28" : "=r"(fbrst));
            fbrst |= 0x200;
            __asm__ volatile("ctc2.ni %0, $vi28" : : "r"(fbrst));
        }
        __asm__ volatile("cfc2.ni %0, $vi29" : "=r"(stat));
    }
    while (GIF_STAT & 0xC00) {
        if (--timeout < 0) {
            GIF_CTRL = 1;
            GIF_MODE = 4;
        }
    }
}
