/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

/* Loads VU0 register $vfN with the four 32-bit words (x, y, z, w). */
#define VU_SET_VF(n, x, y, z, w) do { u64 _x = (x), _y = (y), _z = (z), _w = (w); u128 _v; __asm__("pcpyld %0, %1, %2" : "=r"(_v) : "r"(_w << 32 | _z), "r"(_y << 32 | _x)); __asm__ volatile("qmtc2.i %0, $vf" #n : : "r"(_v)); } while (0)

struct State {
    char pad0[0x18];
    u32 qwc;
    char pad1C[0x30 - 0x1C];
    u32 tag[4];
    char pad40[0x1FC - 0x40];
    u128 *top;
    char pad200[0xAF0 - 0x200];
    u128 vAF0;
    u128 vB00;
    u32 scale;
    u32 alpha;
};

extern "C" void func_0046CB90(State *s) {
    u128 *p;

    __asm__ volatile("lqc2 $vf1, %0" : : "m"(s->vAF0));
    VU_SET_VF(2, 0x437F0000, 0x437F0000, 0x437F0000, s->alpha);
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(s->vB00));
    p = s->top - 3;
    s->top = p;
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(p[0]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(p[1]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(p[2]));
    u32 addr = (u32)p & 0x0FFFFFFF;
    u32 size = 0x2A1;
    u32 tag = 0x30000003;
    u32 command = 0x6C03C0C9;
    s->tag[3] = command;
    s->qwc = size;
    s->tag[0] = tag;
    s->tag[1] = addr;
    s->tag[2] = 0;
}
