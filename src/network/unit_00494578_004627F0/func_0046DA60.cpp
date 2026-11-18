/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef float f32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct Self {
    char b0;
    char b1;
    char b2;
    char b3;
    char pad4[0x2D8 - 4];
    s32 f2D8;
    f32 f2DC;
    char pad2E0[0xED0 - 0x2E0];
    u128 m[3][4];
    s16 hF90;
    s16 hF92;
    s16 hF94;
    char padF96[0xFBC - 0xF96];
    f32 fFBC;
    f32 fFC0;
    f32 fFC4;
    f32 fFC8;
    f32 fFCC;
    f32 fFD0;
    f32 fFD4;
    f32 fFD8;
    f32 fFDC;
};

extern "C" void func_004751FC(void);
extern f32 D_00604E70;
extern char D_0058B288[];
extern char *D_0058B280;

extern "C" void func_0046DA60(Self *self) {
    func_004751FC();
    __asm__ volatile("sqc2 $vf28, %0" : "=m"(self->m[0][0]));
    __asm__ volatile("sqc2 $vf29, %0" : "=m"(self->m[0][1]));
    __asm__ volatile("sqc2 $vf30, %0" : "=m"(self->m[0][2]));
    __asm__ volatile("sqc2 $vf31, %0" : "=m"(self->m[0][3]));
    __asm__ volatile("sqc2 $vf28, %0" : "=m"(self->m[1][0]));
    __asm__ volatile("sqc2 $vf29, %0" : "=m"(self->m[1][1]));
    __asm__ volatile("sqc2 $vf30, %0" : "=m"(self->m[1][2]));
    __asm__ volatile("sqc2 $vf31, %0" : "=m"(self->m[1][3]));
    __asm__ volatile("sqc2 $vf28, %0" : "=m"(self->m[2][0]));
    __asm__ volatile("sqc2 $vf29, %0" : "=m"(self->m[2][1]));
    __asm__ volatile("sqc2 $vf30, %0" : "=m"(self->m[2][2]));
    __asm__ volatile("sqc2 $vf31, %0" : "=m"(self->m[2][3]));
    __asm__ volatile("ctc2.i %0, $vi13" : : "r"(0));
    f32 v = D_00604E70;
    self->fFC0 = v;
    self->fFC4 = v;
    self->fFC8 = v;
    self->fFD0 = 0.5f;
    self->fFD8 = 1.0f;
    self->fFDC = 1.0f;
    self->b1 = 0;
    self->b3 = 0;
    self->f2D8 = 0;
    self->f2DC = 1.0f;
    self->hF92 = 0x40;
    self->hF94 = 0x50;
    self->fFCC = v;
    self->fFBC = 255.0f;
    self->fFD4 = 0.5f;
    self->b0 = 1;
    self->hF90 = 0;
    D_0058B280 = D_0058B288;
}
