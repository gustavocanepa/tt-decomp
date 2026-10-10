struct Scale { int m0, m4; };
extern Scale D_00585CC8;
extern "C" void func_00477DC0(unsigned int);
extern "C" void func_0046F0F8(int);
extern "C" void func_00478C98(int);
extern "C" void func_004702D8(int, float);
extern "C" void func_00472268(int, int);
extern "C" void func_004157B0(Scale *, float, float);

extern "C" void func_0038E3F0(void)
{
    func_00477DC0(0x80FFFFFF);
    func_0046F0F8(6);
    func_00478C98(8);
    func_00478C98(5);
    func_00478C98(4);
    func_00478C98(3);
    func_004702D8(0x44, 0.0f);
    func_00472268(2, 1);
    func_00472268(3, 1);
    Scale *s = &D_00585CC8;
    s->m4 = 0;
    func_004157B0(s, 1.0f, 1.0f);
}
