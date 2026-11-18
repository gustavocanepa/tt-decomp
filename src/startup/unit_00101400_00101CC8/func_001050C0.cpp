#include "types.h"
struct A { char p[0x18]; s32 u18; char q[0x28 - 0x1C]; s32 u28; };
struct R { char p[0x10]; s32 u10, u14, u18, u1C; };
extern "C" void func_00104A88(void *, s32);
extern "C" void func_00104C88(void *);
extern "C" void func_00104D10(void *);
extern "C" s32 func_00104F00(void *);
extern "C" void func_004705E0(float, float);
extern "C" void func_00470628(float, float, float, float);
extern "C" void func_00472268(s32, s32);
extern "C" void pglPushAttrib(s32);
extern "C" void func_00473498(void);
extern "C" void func_00474520(float, float, float, float, float, float, float, float);
extern "C" void func_00477E30(float, float, float, float);
extern "C" void func_00478C98(s32);
extern "C" A *func_001050C0(A *a, R *r, s32 x, s32 y) {
    s32 s4 = a->u28;
    func_00104A88(a, 0);
    pglPushAttrib(0x887);
    func_00104D10(r);
    func_00104C88(a);
    func_00470628(0.0f, 0.0f, 1.0f, 1.0f);
    func_004705E0(0.5f, 0.5f);
    func_00472268(3, x);
    func_00472268(2, y);
    func_00478C98(4);
    func_00478C98(6);
    func_00478C98(5);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    float f = (float)a->u18;
    func_00474520(0.0f, 0.0f, f, (float)func_00104F00(a), (float)r->u10, (float)r->u14, (float)(r->u10 + r->u18), (float)(r->u14 + r->u1C));
    func_00473498();
    func_00104A88(a, s4);
    return a;
}
