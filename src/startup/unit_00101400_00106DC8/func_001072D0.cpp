/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tex { char pad[0x12]; unsigned short size; unsigned short m14; short pad2; int m18; };
struct Buf { void *m0; int m4; int m8; int mC; int m10; };
extern "C" void func_00107280(Buf *);
extern "C" void func_00107240(Buf *, int);
extern "C" void func_00466828(Tex *, void *);
extern "C" int func_0046E2B8(void);
extern "C" void func_00467508(Tex *);
extern "C" void func_0046FB08(int);
extern "C" void func_00472628(void);
extern "C" void func_00467640(Tex *);

extern "C" void func_001072D0(Buf *b, Tex *t)
{
    func_00107280(b);
    func_00107240(b, t->size << 6);
    func_00466828(t, b->m0);
    if (func_0046E2B8()) {
        func_00467508(t);
        func_0046FB08(1);
        func_00472628();
    } else {
        func_00467640(t);
    }
    b->m8 = t->m18;
    b->m10 = 0;
    b->mC = t->m14;
}
