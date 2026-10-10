struct Ctx { int m0, m4, m8; };
extern "C" void func_00104C88(Ctx *);
extern "C" void func_00478C98(int);
extern "C" void func_0046F0F8(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00477E30(float, float, float, float);
extern "C" int func_00104E00(Ctx *);
extern "C" void func_00474090(int, int, int, int);

extern "C" void func_0038C1F8(void *self, Ctx *c)
{
    func_00104C88(c);
    func_00478C98(5);
    func_0046F0F8(6);
    func_004702D8(0xA4, 1.0f);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    int m8 = c->m8;
    func_00474090(0, 0, m8, func_00104E00(c));
}
