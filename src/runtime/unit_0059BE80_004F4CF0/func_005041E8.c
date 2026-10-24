/* compiler: ee-gcc2.9-991111 */
typedef unsigned long u64;
struct Slot { struct Slot *next; char pad[0x3C]; };
struct Timers {
    u64 f0;
    int f8;
    int pad;
    int f10;
    struct Slot *pool;
};
extern struct Timers D_005A4110;
extern struct Slot D_0078F7C0[0x80];
extern void *func_004F6678(void *, int, unsigned int);
extern int func_004FA510(int, void *, int, int);
extern int func_004FB368(int);
extern int func_005038D8(void);
extern int func_00503928(void);
extern void func_005041B8(int);
extern void func_005041C8(unsigned);
extern void func_005041D8(int);
extern int func_005054B8(void);
extern int func_00504788(int);

int func_005041E8(unsigned int arg0)
{
    int i;
    int id;
    int intr;
    unsigned mode;
    if (D_005A4110.f8 >= 0)
        return 0x80008001;
    D_005A4110.f0 = 0;
    D_005A4110.f10 = 0;
    func_004F6678(D_0078F7C0, 0, 0x2000);
    D_005A4110.pool = D_0078F7C0;
    for (i = 0; i < 0x80; i++)
        D_0078F7C0[i].next = &D_0078F7C0[i + 1];
    D_0078F7C0[0x7F].next = 0;
    func_005054B8();
    id = func_004FA510(0xB, (void *)func_00504788, 0, 0);
    if (id < 0)
        return 0x80009021;
    D_005A4110.f8 = id;
    intr = func_005038D8();
    mode = *(volatile unsigned *)0x10001010;
    mode = (mode & 0xFFFFFFFCU) | arg0;
    mode |= 0x300;
    if (!(mode & 0x80)) {
        mode |= 0xC80;
        func_005041B8(0);
        func_005041D8(0xFFFF);
    }
    func_005041C8(mode);
    func_004FB368(0xB);
    if (intr)
        func_00503928();
    return 0;
}
