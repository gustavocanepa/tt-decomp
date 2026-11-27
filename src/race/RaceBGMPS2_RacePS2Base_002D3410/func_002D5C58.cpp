/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct R { char pad0[8]; s32 w; char pad1[4]; s32 x; s32 y; s32 dx; s32 dy; };

extern "C" void func_00104D10(void *);
extern "C" s32 func_00104E00(void *);
extern "C" void func_0046F0F8(s32);
extern "C" void func_004701C0(s32);
extern "C" void func_00470220(s32, float);
extern "C" void func_00470450(s32);
extern "C" void func_00470E60(s32);
extern "C" void func_00472268(s32, s32);
extern "C" void func_00474520(float, float, float, float, float, float, float, float);
extern "C" void func_00474CB8(s32, s32);
extern "C" void func_00478C98(s32);

extern "C" void func_002D5C58(R *arg0) {
    func_00470E60(2);
    float z = 0.0f;
    func_00104D10(arg0);
    func_00472268(3, 0);
    func_00472268(2, 0);
    func_0046F0F8(5);
    func_0046F0F8(4);
    func_004701C0(1);
    func_00470220(7, z);
    func_00470450(0);
    func_00474CB8(1, 0xFF);
    float w = (float)arg0->w;
    func_00474520(z, z, w, (float)func_00104E00(arg0), (float)arg0->x, (float)arg0->y, (float)(arg0->x + arg0->dx), (float)(arg0->y + arg0->dy));
    func_00478C98(4);
    func_004701C0(3);
    func_00470450(0xFFFFFF);
}
