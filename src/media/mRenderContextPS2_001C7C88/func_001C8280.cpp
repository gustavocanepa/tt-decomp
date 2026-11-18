/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00104C88(void *);
extern "C" void func_00104D10(void *);
extern "C" void func_0046F0F8(int);
extern "C" void func_00470450(int);
extern "C" void func_00470478(int);
extern "C" void func_004704E0(int);
extern "C" void func_00472268(int, int);
extern "C" void pglPushAttrib(int);
extern "C" void func_00473498(void);
extern "C" void func_00474520(float, float, float, float, float, float, float, float);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(int);
extern "C" void func_001C8280(void *a, void *b, float *r, int flag) {
    if (flag != 0) func_00470450(0xFFFFFF);
    pglPushAttrib(0x887);
    func_00104D10(a);
    func_00104C88(b);
    func_004704E0(0);
    func_00472268(3, 0);
    func_00472268(2, 0);
    func_00478C98(4);
    func_00478C98(5);
    func_0046F0F8(6);
    func_00470478(0);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    float x = r[0];
    float y = r[1];
    float x2 = x + r[2];
    float y2 = y + r[3];
    func_00474520(x, y, x2, y2, x, y, x2, y2);
    func_00473498();
    if (flag != 0) func_00470450(-1);
}
