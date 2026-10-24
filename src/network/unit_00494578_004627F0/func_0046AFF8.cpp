/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct State {
    u8 f0;
    u8 mode;
    char pad2[0x18 - 2];
    u32 f18;
    char pad1C[0x30 - 0x1C];
    u32 tag[4];
    char pad40[0x1FC - 0x40];
    u128 *top;
    char pad200[0xB00 - 0x200];
    u128 vB00;
    char padB10[0xF50 - 0xB10];
    u128 m[4];
};

/* Copies the current matrix into $vfA..$vfD: from $vf28..$vf31 in mode 2, else from memory. */
#define VU_GET_MATRIX(s, a, b, c, d) do { if ((s)->mode == 2) { __asm__ volatile("vmove.xyzw $vf" #a ", $vf28"); __asm__ volatile("vmove.xyzw $vf" #b ", $vf29"); __asm__ volatile("vmove.xyzw $vf" #c ", $vf30"); __asm__ volatile("vmove.xyzw $vf" #d ", $vf31"); } else { __asm__ volatile("lqc2 $vf" #a ", %0" : : "m"((s)->m[0])); __asm__ volatile("lqc2 $vf" #b ", %0" : : "m"((s)->m[1])); __asm__ volatile("lqc2 $vf" #c ", %0" : : "m"((s)->m[2])); __asm__ volatile("lqc2 $vf" #d ", %0" : : "m"((s)->m[3])); } } while (0)

extern "C" void func_0046AFF8(State *s) {
    u128 *p;
    VU_GET_MATRIX(s, 1, 2, 3, 4);
    __asm__ volatile("lqc2 $vf5, %0" : : "m"(s->vB00));
    p = s->top - 5;
    s->top = p;
    __asm__ volatile("sqc2 $vf1, %0" : "=m"(p[0]));
    __asm__ volatile("sqc2 $vf2, %0" : "=m"(p[1]));
    __asm__ volatile("sqc2 $vf3, %0" : "=m"(p[2]));
    __asm__ volatile("sqc2 $vf4, %0" : "=m"(p[3]));
    __asm__ volatile("sqc2 $vf5, %0" : "=m"(p[4]));
    u32 addr = (u32)p & 0x0FFFFFFF;
    u32 size = 0x2C1;
    u32 tag = 0x30000005;
    u32 command = 0x6C05C0C9;
    s->tag[3] = command;
    s->f18 = size;
    s->tag[0] = tag;
    s->tag[1] = addr;
    s->tag[2] = 0;
}
