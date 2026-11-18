/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Scratch {
    u8 dirty;
    u8 current;
    char pad2;
    u8 f3;
    char pad4[0xA];
    u8 fE;
    char padF[0x39];
    u16 flags;
    char pad4A[0xB86];
    u128 vf5;
    char padBE0[0x2F0];
    u128 matrix[3][4];
};

/* Refreshes the VU0 view (vf24-vf27) and world (vf1-vf4) matrices from the current matrix set and
   runs the microprogram at 0x858 that combines them. */
extern "C" void func_0046BF20(Scratch *s) {
    switch (s->current) {
    case 0:
        __asm__ volatile("vmove.xyzw $vf24, $vf28");
        __asm__ volatile("vmove.xyzw $vf25, $vf29");
        __asm__ volatile("vmove.xyzw $vf26, $vf30");
        __asm__ volatile("vmove.xyzw $vf27, $vf31");
        __asm__ volatile("lqc2 $vf1, %0" : : "m"(s->matrix[1][0]));
        __asm__ volatile("lqc2 $vf2, %0" : : "m"(s->matrix[1][1]));
        __asm__ volatile("lqc2 $vf3, %0" : : "m"(s->matrix[1][2]));
        __asm__ volatile("lqc2 $vf4, %0" : : "m"(s->matrix[1][3]));
        break;
    case 1:
        __asm__ volatile("vmove.xyzw $vf1, $vf28");
        __asm__ volatile("vmove.xyzw $vf2, $vf29");
        __asm__ volatile("vmove.xyzw $vf3, $vf30");
        __asm__ volatile("vmove.xyzw $vf4, $vf31");
        __asm__ volatile("lqc2 $vf24, %0" : : "m"(s->matrix[0][0]));
        __asm__ volatile("lqc2 $vf25, %0" : : "m"(s->matrix[0][1]));
        __asm__ volatile("lqc2 $vf26, %0" : : "m"(s->matrix[0][2]));
        __asm__ volatile("lqc2 $vf27, %0" : : "m"(s->matrix[0][3]));
        break;
    case 2:
    default:
        __asm__ volatile("vnop");
        __asm__ volatile("lqc2 $vf24, %0" : : "m"(s->matrix[0][0]));
        __asm__ volatile("lqc2 $vf25, %0" : : "m"(s->matrix[0][1]));
        __asm__ volatile("lqc2 $vf26, %0" : : "m"(s->matrix[0][2]));
        __asm__ volatile("lqc2 $vf27, %0" : : "m"(s->matrix[0][3]));
        __asm__ volatile("lqc2 $vf1, %0" : : "m"(s->matrix[1][0]));
        __asm__ volatile("lqc2 $vf2, %0" : : "m"(s->matrix[1][1]));
        __asm__ volatile("lqc2 $vf3, %0" : : "m"(s->matrix[1][2]));
        __asm__ volatile("lqc2 $vf4, %0" : : "m"(s->matrix[1][3]));
        break;
    }
    if (s->fE)
        __asm__ volatile("lqc2 $vf5, %0" : : "m"(s->vf5));
    else
        __asm__ volatile("vaddw.xyzw $vf5, $vf0, $vf0w");
    __asm__ volatile("vcallms 0x7A0");
    s->dirty = 0;
    s->f3 = 0;
    s->flags |= 2;
}
