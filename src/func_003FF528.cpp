/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Name { char c[8]; };
extern Name D_006A6110;
struct Obj {
    s32 pad0;
    Name n4;
    char pad1[0x38];
    s32 f44;
    Name n48;
    char pad2[0x38];
    s32 f88, f8c, f90, f94, f98, f9c, fa0, fa4, fa8, fac;
};
extern "C" void *func_004F6678(void *, int, unsigned int);
extern "C" void func_003FF528(Obj *self) {
    func_004F6678(&self->n4, 0, 0xAC);
    __builtin_strcpy(self->n4.c, "Player1");
    self->f44 = 0;
    __builtin_strcpy(self->n48.c, "Player1");
    self->f94 = 2;
    self->f88 = 0;
    self->f8c = 1;
    self->f90 = 1;
    self->f98 = 0;
    self->f9c = 0;
    self->fa0 = 1;
    self->fa4 = 0;
    self->fa8 = 1;
    self->fac = 0;
}
