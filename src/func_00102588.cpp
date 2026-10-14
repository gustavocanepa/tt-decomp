typedef int s32;
typedef unsigned short u16;
struct O { char p[0x14]; u16 u14; char q[2]; char *u18; };
extern "C" int func_00467728(void *);
extern "C" void func_0046AC48(void *);
extern "C" void func_0046D810(s32, s32, s32, s32, s32, s32);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004702D8(s32, float);
extern "C" void func_00473178(s32);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004738A0(float, float, float, float, float, float);
extern "C" void func_004751FC(void);
extern "C" void func_00475638(float, float, float);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(s32);
extern s32 D_00579518;
extern "C" void func_00102588(void *self, float *f, O *o, s32 *a, s32 *b, s32 idx) {
    if (o) {
        if (!(idx < o->u14)) idx = 0;
        s32 off = idx * 4;
        void *s3 = o->u18 + idx * 0x28;
        func_00473178(1);
        func_00473050();
        func_004751FC();
        func_004738A0(-320.0f, 320.0f, -224.0f, 224.0f, -1.0f, 1.0f);
        if (D_00579518) func_00475638(0.75f, 1.0f, 1.0f);
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
        func_004702D8(0x44, 1.0f);
        func_00467728(o);
        func_0046AC48(s3);
        func_00477E30(f[0], f[1], f[2], f[3]);
        func_0046D810(4, a[idx], b[idx], 0, 0, 0);
        func_00473178(1);
        func_004730A8();
        func_00473178(0);
        func_004730A8();
    }
}
