typedef unsigned int u32;
struct State { int a, b, arg, c, dma, intc; };
extern State D_00776B90;
extern "C" int func_004FB300(void *);
extern "C" int func_004BB6E8(int, void *, void *);
extern "C" int func_004BB728(int, void *, void *);
typedef int (*Handler)(int, void *, void *);
extern "C" int func_004FA510(int, Handler, int, State *);
extern "C" int func_004FA540(int, Handler, int, State *);
extern "C" int func_004CBBE0(u32, u32);
#define DSTAT (*(volatile u32 *)0x1000E010)
extern "C" void func_004BB3C0(int arg) {
    char frame_[32];
    State *p = &D_00776B90;
    p->arg = arg;
    func_004FB300((void *)8);
    volatile u32 *stat = (volatile u32 *)0x1000E010;
    struct Status { u32 word; } old = { *stat };
    *stat = 8;
    (void)DSTAT;
    __asm__ volatile("sync");
    if (old.word & 0x80000) {
        DSTAT = 0x80000;
        (void)DSTAT;
    __asm__ volatile("sync");
    }
    Status old2 = { DSTAT };
    DSTAT = 16;
    (void)DSTAT;
    __asm__ volatile("sync");
    if (old2.word & 0x100000) {
        DSTAT = 0x100000;
        (void)DSTAT;
    __asm__ volatile("sync");
    }
    p->dma = func_004FA510(8, func_004BB6E8, 0, p);
    p->intc = func_004FA540(3, func_004BB728, 0, p);
    func_004CBBE0(8, 8);
}
