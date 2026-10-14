/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Obj { char p0[4]; s32 f4; };
struct S { char p[0x6E14]; Obj *o; };
extern "C" void func_00439EC8(void *, void *);
extern "C" void func_0043A080(void *, int, int, int, int);
extern "C" void func_0043A150(void *, int, int, int);
extern "C" void func_0043A168(void *, s32, s32, s32);
extern "C" void func_0043FF78(void *);
extern "C" void func_00478C98(s32);
extern "C" void func_0043B1B8(S *self, s32 a1, s32 a2, s32 a3, s32 a4) {
    func_0043A168(self->o, a1, a2, a2);
    func_0043A150(self->o, a3, a4, 0xFF);
    Obj *t = self->o;
    func_00478C98(2);
    t->f4 = 0;

    func_00439EC8(self->o, (void *)0x80000000);
    func_0043A080(self->o, 0, 0, 0, 0);
    func_0043FF78(self);
    func_0043A080(self->o, 1, 1, 1, 1);
}
