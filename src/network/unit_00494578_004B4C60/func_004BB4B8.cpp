/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct State { int pad[4]; int a,b,c; };
extern State D_00776B90;
extern "C" int func_004FB300(void *);
extern "C" int func_004FA520(int,int);
extern "C" int func_004FA550(int,int);
extern "C" void *func_004F6678(void *,int,unsigned int);
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")
extern "C" void *func_004BB4B8(void) {
    State *s = &D_00776B90;
    func_004FB300((void *)8);
    volatile u32 *stat = (volatile u32 *)0x1000E010;
    u32 old = *stat;
    *stat = 8;
    (void)*stat; SYNC();
    if (old & 0x80000) {
        REG(0x1000E010) = 0x80000;
        (void)REG(0x1000E010); SYNC();
    }
    u32 old2 = REG(0x1000E010);
    REG(0x1000E010) = 16;
    (void)REG(0x1000E010); SYNC();
    if (old2 & 0x100000) {
        REG(0x1000E010) = 0x100000;
        (void)REG(0x1000E010); SYNC();
    }
    func_004FA520(8,s->a);
    func_004FA550(3,s->b);
    REG(0x1000E020) &= ~8;
    SYNC();
    return func_004F6678(s,0,28);
}
