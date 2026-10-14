/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

static inline float sqrt_s(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }

struct Obj {
    char pad0[8];
    f32 m8;
    f32 mC;
    char pad1[0xE8 - 0x10];
    s32 mE8;
    char pad2[0x140 - 0xEC];
    s32 m140;
    char pad3[0x184 - 0x144];
    f32 m184;
    f32 m188;
    f32 m18C;
    f32 m190[3];
    f32 m19C;
};

extern "C" f32 func_003173B0(void *) throw();
extern "C" f32 func_003173F8(void *) throw();
extern "C" void func_0046E150(void);
extern "C" void func_0046E1B0(void);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_004752F8(void *);
extern "C" void func_004755EC(f32, f32, f32);
extern "C" void func_00475730(f32);
extern "C" void func_00475758(float);
extern "C" void func_00475780(float);
extern "C" f32 func_00552A38(f32 *);
extern "C" void func_00552A68(float *, float *);
extern "C" void func_00552C90(void *, void *);

extern "C" s32 func_0032D5B8(Obj *self) {
    f32 A[4];
    f32 ang[4];
    f32 *p184 = &self->m184;
    f32 *px = &ang[0];
    func_00552A68(self->m190, A);
    func_00552C90(A, p184);
    f32 len = sqrt_s(func_00552A38(A));
    f32 t = func_003173B0(A);
    f32 *py = &ang[1];
    *py = t;
    *px = func_003173F8(A);
    self->m8 = len;
    self->mC = self->m19C;
    f32 *pz = &ang[2];
    *pz = 0.0f;
    if ((f32)self->m140 / 60.0f >= 1.0f)
        self->mE8 = 3;
    func_0046E150();
    func_00473050();
    func_004751FC();
    func_00475780(*pz);
    func_00475730(*py);
    func_00475758(*px);
    func_004755EC(-*p184, -self->m188, -self->m18C);
    func_004752F8((char *)self + 0x100);
    func_004730A8();
    func_0046E1B0();
    return 1;
}
