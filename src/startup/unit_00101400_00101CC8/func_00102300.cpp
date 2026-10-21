#include "types.h"
extern "C" {
void func_0046D810(s32, void *, s32, s32, s32, s32);
void func_0046F0F8(s32);
void func_004702D8(s32, float);
void func_00473178(s32);
void func_00473050(void);
void func_004730A8(void);
void func_004738A0(float, float, float, float, float, float);
void func_004751FC(void);
void func_00477E30(float, float, float, float);
void func_00478C98(s32);
}
extern char D_00579340[];
struct V { float a, b, c, d; };
extern "C" void func_00102300(V *arg0) {
    func_00473178(1);
    func_00473050();
    func_004751FC();
    func_004738A0(-320.0f, 320.0f, -224.0f, 224.0f, -1.0f, 1.0f);
    func_00473178(0);
    func_00473050();
    func_004751FC();
    func_00478C98(0xF);
    func_00478C98(0x11);
    func_00478C98(5);
    func_00478C98(4);
    func_0046F0F8(2);
    func_00478C98(8);
    func_00478C98(6);
    func_0046F0F8(6);
    func_004702D8(0x44, 1.0f);
    func_00477E30(arg0->a, arg0->b, arg0->c, arg0->d);
    func_0046D810(4, D_00579340, 0, 0, 0, 0);
    func_00473178(1);
    func_004730A8();
    func_00473178(0);
    func_004730A8();
}
