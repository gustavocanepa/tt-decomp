typedef int s32;
struct Obj { char pad[0x2E8]; float f2E8; char pad1[0x308 - 0x2EC]; float f308; s32 i30C; };
struct E16 { char b[16]; };
extern E16 D_00579848[];
extern "C" void func_0011C730(void);
extern "C" s32 func_0011C798(void *, s32);
extern "C" void func_0011AF70(void *, s32, void (*)(void), E16 *, float, float);
extern "C" void func_0046F0F8(s32);
extern "C" s32 func_0046F7F8(void);
extern "C" void func_0046F8D8(void);
extern "C" void func_0046F988(s32);
extern "C" void func_004702D8(s32, float);
extern "C" void func_004705E0(float, float);
extern "C" void func_00478C98(s32);

extern "C" void func_0011B830(Obj *arg0, s32 arg1, float fp) {
    if (func_0011C798(arg0, arg1) != 0) {
        float t = (arg0->f308 / (float)arg0->i30C) / arg0->f2E8;
        func_0046F0F8(9);
        func_00478C98(6);
        func_004702D8(0x44, 1.0f);
        s32 s = func_0046F7F8();
        func_0011AF70(arg0, arg1, func_0011C730, &D_00579848[arg1], fp, t);
        func_0046F8D8();
        func_00478C98(9);
        func_004705E0(0.0f, 0.0f);
        func_0046F988(s);
        func_004705E0(1.0f, 0.0f);
        func_0046F988(s);
        func_004705E0(0.0f, 1.0f);
        func_0046F988(s);
        func_004705E0(1.0f, 1.0f);
        func_0046F988(s);
        func_004705E0(0.5f, 0.5f);
        func_0046F988(s);
    }
}
