/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Q { char pad[0x18]; s32 f18; };
struct V4 { float x, y, z, w; };
extern Q *D_00579304;
extern char D_00579340[];
extern char D_00579400[];
extern "C" int func_00467728(void *);
extern "C" void func_0046AC48(s32);
extern "C" void func_0046D810(s32, void *, void *, s32, s32, s32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004702D8(s32, float);
extern "C" void func_00473178(s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004738A0(float, float, float, float, float, float);
extern "C" void func_004751FC(void);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(s32);

extern "C" void func_00102430(V4 *arg0) {
    float one = 1.0f;
    Q *s1 = D_00579304;
    s32 s2 = s1->f18;
    func_00473178(1);
    func_00473050();
    func_004751FC();
    func_004738A0(-320.0f, 320.0f, -224.0f, 224.0f, -1.0f, one);
    func_00473178(0);
    func_00473050();
    func_004751FC();
    func_00478C98(0xF);
    func_00478C98(0x11);
    func_00478C98(5);
    func_00478C98(4);
    func_0046F0F8(2);
    func_00478C98(8);
    func_0046F0F8(6);
    func_004702D8(0x44, one);
    func_00467728(s1);
    func_0046AC48(s2);
    func_00477E30(arg0->x, arg0->y, arg0->z, arg0->w);
    func_0046D810(4, D_00579340, D_00579400, 0, 0, 0);
    func_00473178(1);
    func_004730A8();
    func_00473178(0);
    func_004730A8();
}
