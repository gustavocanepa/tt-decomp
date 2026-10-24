/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char pad[0xB8]; s32 fA4; s32 fA8; s32 fAC; };
extern "C" void func_00188000(void *);
extern "C" void func_001880E8(void *);
extern "C" void func_001C7410(int);
extern "C" void func_00187BC0(Obj *self) {
    s32 a;
    a = self->fA4;
    if (a == 0) {
        do {
            switch (self->fAC) {
            case 0:
                func_001C7410(1);
                a = self->fA4;
                break;
            case 1:
                func_001C7410(1);
                a = self->fA4;
                break;
            case 2:
                func_001880E8(self);
                func_00188000(self);
                self->fAC = 1;
                a = self->fA4;
                break;
            case 3:
                self->fA4 = 1;
                a = 1;
                break;
            }
        } while (a == 0);
    }
}
