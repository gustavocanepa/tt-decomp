/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

typedef struct Self { char *vtbl; s32 m4; s32 m8; char *mC; char m10[20]; } Self;
extern char D_005DA498[];
extern char D_0076FC88[];
void *func_0047C268(void *);
void func_0047BF20(Self *, s32, s32);

void func_0047BEB0(Self *self, s32 a, s32 b) {
    self->vtbl = D_005DA498;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = D_0076FC88;
    func_0047C268(self->m10);
    func_0047BF20(self, a, b);
}
