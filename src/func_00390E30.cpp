typedef int s32;

extern "C" int func_00467728(char *self);
extern "C" void func_00469BB0(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0);
extern "C" void func_0046AC48(s32 a0);
extern "C" void func_0046F0F8(s32 a0);
extern "C" void func_004702D8(s32 a0, float f12);
extern "C" void func_00470478(s32 a0);
extern "C" void func_00472268(s32 a0, s32 a1);
extern "C" void func_00473050(void);
extern "C" void func_004730A8(void);
extern "C" void func_004751FC(void);
extern "C" void func_00478C98(s32 a0);

extern "C" void func_00390E30(char *arg0) {
    func_00478C98(4);
    func_0046F0F8(6);
    func_0046F0F8(5);
    func_0046F0F8(2);
    func_00470478(0);
    func_004702D8(0x68, 1.0f);
    func_00478C98(0xF);
    func_00472268(0, 1);
    func_00472268(1, 0);
    char *v = *(char **)(arg0 + 0x88);
    if (v != 0) {
        func_00467728(v);
        func_0046AC48(*(s32 *)(*(char **)(arg0 + 0x88) + 0x18));
    }
    func_00473050();
    func_004751FC();
    func_00469BB0(4, 0x32, 0x31, 0x27, 0x31);
    func_004730A8();
}
