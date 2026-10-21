/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Packet {
    char pad0[0x18];
    u32 vifAddr;
    char pad1C[0x14];
    u32 tag[4];
    char pad40[0x1BC];
    u128 *stack;
    char pad200[0xE0];
    u128 light[8];
    char pad360[0x7B0];
    u32 intensity;
    u32 alpha;
};

/* Loads VU0 register $vfN with the four 32-bit words (x, y, z, w). */
#define VU_SET_VF(n, x, y, z, w) do { u64 _x = (x), _y = (y), _z = (z), _w = (w); u128 _v; __asm__("pcpyld %0, %1, %2" : "=r"(_v) : "r"(_w << 32 | _z), "r"(_y << 32 | _x)); __asm__ volatile("qmtc2.i %0, $vf" #n : : "r"(_v)); } while (0)

/* Pushes the eight light quadwords (the last five scaled by the intensity) and the colour
   (255, 255, 255, alpha) on the packet stack, pointing the DMA REF tag and VIF UNPACK at them. */
extern "C" void func_0046C138(Packet *pk) {
    u128 *p;

    VU_SET_VF(9, 0x437F0000, 0x437F0000, 0x437F0000, pk->alpha);
    VU_SET_VF(10, pk->intensity, pk->intensity, pk->intensity, pk->alpha);
    __asm__ volatile("lqc2 $vf1, %0" : : "m"(pk->light[0]));
    __asm__ volatile("lqc2 $vf2, %0" : : "m"(pk->light[1]));
    __asm__ volatile("lqc2 $vf3, %0" : : "m"(pk->light[2]));
    __asm__ volatile("lqc2 $vf4, %0" : : "m"(pk->light[3]));
    __asm__ volatile("lqc2 $vf5, %0" : : "m"(pk->light[4]));
    __asm__ volatile("lqc2 $vf6, %0" : : "m"(pk->light[5]));
    __asm__ volatile("lqc2 $vf7, %0" : : "m"(pk->light[6]));
    __asm__ volatile("lqc2 $vf8, %0" : : "m"(pk->light[7]));
    __asm__ volatile("vmul.xyzw $vf4, $vf4, $vf10");
    __asm__ volatile("vmul.xyzw $vf5, $vf5, $vf10");
    __asm__ volatile("vmul.xyzw $vf6, $vf6, $vf10");
    __asm__ volatile("vmul.xyzw $vf7, $vf7, $vf10");
    __asm__ volatile("vmul.xyzw $vf8, $vf8, $vf10");
    p = pk->stack - 9;
    pk->stack = p;
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(p[0]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(p[1]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(p[2]));
    __asm__ volatile("sqc2 $vf4, %0" : "=m"(p[3]));
    __asm__ volatile("sqc2 $vf5, %0" : "=m"(p[4]));
    __asm__ volatile("sqc2 $vf6, %0" : "=m"(p[5]));
    __asm__ volatile("sqc2 $vf7, %0" : "=m"(p[6]));
    __asm__ volatile("sqc2 $vf8, %0" : "=m"(p[7]));
    __asm__ volatile("sqc2 $vf9, %0" : "=m"(p[8]));
    u32 addr = (u32)p & 0x0FFFFFFF;
    u32 size = 0x169;
    u32 tag = 0x30000009;
    u32 command = 0x6C09C0C9;
    pk->tag[3] = command;
    pk->vifAddr = size;
    pk->tag[0] = tag;
    pk->tag[1] = addr;
    pk->tag[2] = 0;
}
