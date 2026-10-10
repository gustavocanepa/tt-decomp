extern "C" void func_00477DC0(void);
extern "C" void func_004702D8(int mode, float value);
extern "C" void func_0046F0F8(int n);
extern "C" void func_00478C98(int n);
extern "C" void func_00470478(int n);
extern "C" void func_00475A88(int *a, int *b, int *c, int *d);
extern "C" void func_00474090(int a, int b, int c, int d);

extern "C" void func_002D90D8(float value)
{
    int r[4];
    func_00477DC0();
    func_004702D8(0x21, value);
    func_0046F0F8(6);
    func_00478C98(5);
    func_00470478(0);
    func_00475A88(&r[0], &r[1], &r[2], &r[3]);
    func_00474090(r[0], r[1], r[2], r[3]);
}
